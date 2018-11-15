#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"

int checkVillage(struct gameState *G, int handpos, int bonus, int p){
	struct gameState pre;
	memcpy (&pre, G, sizeof(struct gameState));

	int r = 0;
	r = cardEffect(village, 0, 0, 0, G, handpos, &bonus);
	//pre.handCount[p] = pre.handCount[p];
	//pre.deckCount[p] = pre.deckCount[p] - 3;
	//pre.playedCardCount++;
	
	if (pre.deckCount[p] > 0){
		pre.handCount[p]++;
		pre.hand[p][pre.handCount[p]-1]=pre.deck[p][pre.deckCount[p]-1];
		pre.deckCount[p]--;
	}else if (pre.discardCount[p]>0){
		memcpy(pre.deck[p], G->discard[p], sizeof(int) * pre.discardCount[p]);
		memcpy(pre.discard[p], G->discard[p], sizeof(int)*pre.discardCount[p]);
		pre.hand[p][G->handCount[p]-1] = G->hand[p][G->handCount[p]-1];
		pre.handCount[p]++;
		pre.deckCount[p] = pre.discardCount[p] - 1;
		pre.discardCount[p] = 0;
	}

	pre.numActions = pre.numActions + 2;	
	
	//discardCard(handpos, p, &pre, 0);	

	//pre.playedCards[pre.playedCardCount] = pre.hand[p][handpos];
	//pre.playedCardCount++;
	//pre.handCount[p]--;
	//pre.hand[p][handpos] = -1;

	printf("pre1: %i, post1: %i\n", pre.hand[p][handpos], G->hand[p][handpos]);
	printf("pre2: %i, post2: %i\n", pre.hand[p][pre.handCount[p] -1], G->hand[p][pre.handCount[p]-1]);
	printf("pre3: %i, post3: %i\n", pre.handCount[p], G->handCount[p]);
	assert(memcmp(&pre, G, sizeof(struct gameState)) == 0);
	assert(r == 0);
}

int main() {
	int i, n, p;
	//int k[10] = {adventurer, council_room, feast, gardens, mine,
	//	     remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int handpos = 0, bonus = 0;
	printf("Testing Village Card. \n");

	SelectStream(2);
	PutSeed(3);
	for (n = 0; n<200 ; n++){
		for (i = 0; i< sizeof(struct gameState); i++){
			((char*)&G)[i] = floor(Random() * 256);
		}
		//printf("test1 ");
		p = floor(Random() *2 );
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		G.playedCardCount = floor(Random() * MAX_DECK);
		G.whoseTurn = p;
		G.numPlayers = p;
		handpos = floor(Random() * MAX_HAND);
		G.hand[p][handpos] = floor(Random() * 10);
		G.hand[p][G.handCount[p] - 1] = floor(Random() *10);
		//handpos = floor(Random() * MAX_HAND);
		//printf("test2 \n");
		checkVillage(&G, handpos, bonus, p);
		//cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);	
		printf("n: %i\n", n);
	}	
	printf("Tests Complete");
	exit(0);


}

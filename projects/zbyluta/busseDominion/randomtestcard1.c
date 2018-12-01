#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"

int checkSmithy(struct gameState *G, int handpos, int bonus, int p){
	struct gameState pre;
	memcpy (&pre, G, sizeof(struct gameState));

	int r = 0;
	r = cardEffect(smithy, 0, 0, 0, G, handpos, &bonus);
	//pre.handCount[p] = pre.handCount[p] + 3;
	//pre.deckCount[p] = pre.deckCount[p] - 3;
	//pre.playedCardCount++;
	//pre.hand[p][pre.handCount[p]-1] = pre.deck[p][pre.deckCount[p]-1]';
	//pre.deckCount[p]--;
	
	int i;
	for(i = 0; i <=3;i++){
		if(pre.handCount[p]>0){
			pre.handCount[p]++;
			pre.hand[p][pre.handCount[p]-1] = pre.deck[p][pre.deckCount[p]-1];
			pre.deckCount[p]--;
		}else if (pre.discardCount[p] > 0){
			memcpy(pre.deck[p], G->deck[p], sizeof(int) * pre.discardCount[p]);
			memcpy(pre.discard[p], G->discard[p], sizeof(int) * pre.discardCount[p]);
			pre.hand[p][G->handCount[p]-1] = G->hand[p][G->handCount[p]-1];
			pre.handCount[p]++;
			pre.deckCount[p] = pre.discardCount[p]-1;
			pre.discardCount[p] = 0;
		}
	}
	discardCard(handpos,p, &pre, 0);	
	printf("before: %d, after: %d\n", pre.handCount[p], G->handCount[p]);
	//assert(memcmp(&pre, G, sizeof(struct gameState)) == 0);	
	assert(pre.handCount[p] == G->handCount[p]);
	assert(r == 0);
}

int main() {
	int i, n, p;
	//int k[10] = {adventurer, council_room, feast, gardens, mine,
	//	     remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int handpos = 0, bonus = 0;
	printf("Testing Smithy Card. \n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n< 2000; n++){
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
		//printf("test2 \n");
		checkSmithy(&G, handpos, bonus, p);
		//cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);	
	}	
	printf("Tests Complete");
	exit(0);


}

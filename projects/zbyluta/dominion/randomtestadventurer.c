#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"

int checkAdventurer(struct gameState *G, int handpos, int bonus, int p){
	int r, cardDrawn,lastdiscard, cardsDiscarded = 0;
	struct gameState pre;
	//printf("test\n");
	memcpy (&pre, G, sizeof(struct gameState));
	//printf("test2\n");
	int drawntreasure = 0, currentDeck = pre.deckCount[p];
	//printf("\n");
		while(drawntreasure <2 && currentDeck > 0){
			cardDrawn = pre.deck[p][currentDeck];
			if((cardDrawn == copper )|| cardDrawn == silver || cardDrawn == gold)
			{
				drawntreasure++;
				//printf("found Treasure\n");
			}else{
				cardsDiscarded++;
				lastdiscard = cardDrawn;
				//printf("discarded card \n");
			}
			currentDeck--;
		
		}
	printf("current deck: %i\n", currentDeck);
	r = cardEffect(adventurer, 0, 0, 0, G, handpos, &bonus);
	printf("pre top discard: %i post top discard: %i\n", pre.discard[p][pre.discardCount[p]-1], G->discard[p][pre.discardCount[p]]);
	printf("cards discarded: %i\n", cardsDiscarded);
	printf("pre handCount: %i post hand count: %i\n", pre.handCount[p], G->handCount[p]);
	printf("pre discard Count: %i, post discard count: %i\n", pre.discardCount[p], G->discardCount[p]);

	
	
	assert(r == 0);
}

int main() {
	int i, n, r, p, deckCount, discardCount, handCount;
	//int k[10] = {adventurer, council_room, feast, gardens, mine,
	//	     remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int handpos = 0, choice1 = 0, choice2 = 0 , choice3 = 0, bonus = 0;
	printf("Testing Adventurer Card. \n");

	SelectStream(2);
	PutSeed(3);
	
	for (n = 0; n< 200; n++){
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
		for (i = 0; i<G.deckCount[p];i++){
			G.deck[p][i] = floor(Random() * 26);
		}
		for (i = 0; i<G.handCount[p]; i++){
			G.hand[p][i] = floor(Random() * 26);
		}
		for (i = 0; i<G.discardCount[p];i++){
			G.discard[p][i] = floor(Random() * 26);
		}
		//printf("test2 \n");
		checkAdventurer(&G, handpos, bonus, p);
			
	}	
	printf("Tests Complete");
	exit(0);


}

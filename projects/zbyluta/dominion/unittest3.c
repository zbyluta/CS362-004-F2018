/*-------------------------------------------
 * unit test 2 for endTurn() function
 * ------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
	int i;
	int seed = 5;
	int numPlayer = 3;
	int maxBonus = 10;
	int gameOver = 0;
	int p, r, handCount;
	int bonus;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	p=0;
	handCount =1;
	struct gameState G;
	int maxHandCount = 5;

	printf("---------TESTING endTurn():-----------\n");

	memset(&G, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);
	//G.handCount[p] = handCount;
	printf("Player 0 turn:\n");	
	printf("whoseTurn = %d, expected = 0\n", whoseTurn(&G));
	printf("numActions = %d, expected = 1\n", G.numActions);
	printf("numBuys = %d, expected = 1\n", G.numBuys);
	printf("coins = %d, expected = 3\n", G.coins);
	printf("outpostPlayed = %d, expected = 0\n", G.outpostPlayed);
	printf("handCount Player 0 = %d, expected = 5\n", G.handCount[0]);
	printf("handCount Player 1 = %d, expected = 0\n", G.handCount[1]);
	printf("playedCardCount = %d, expected = 0\n", G.playedCardCount);
	endTurn(&G);	
	printf("Player 1 turn: \n");
	printf("whoseTurn = %d, expected = 1\n", whoseTurn(&G));
	printf("numActions = %d, expected = 1\n", G.numActions);
	printf("numBuys = %d, expected = 1\n", G.numBuys);
	printf("coins = %d, expected = 3\n", G.coins);
	printf("outpostPlayed = %d, expected = 0\n", G.outpostPlayed);
	printf("handCount Player 0= %d, expected = 0\n", G.handCount[0]);
	printf("handCount Player 1= %d, expected = 5\n", G.handCount[1]);
	printf("playedCardCount = %d, expected = 0\n", G.playedCardCount);	

	printf("---------Testing Complete-------------\n");
	return 0;


}

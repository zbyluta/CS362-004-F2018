/*-------------------------------------------
 * unit test 2 for whoseTurn() function
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

	printf("TESTING whoseTurn():\n");

	memset(&G, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);
	G.handCount[p] = handCount;
	
	printf("whoseTurn = %d, expected = 0\n", whoseTurn(&G));
	G.whoseTurn = 2;	
	
	printf("whoseTurn = %d, expected = 2\n", whoseTurn(&G));	
	
	G.whoseTurn = 1;
	printf("whoseTurn = %d, expected = 1\n", whoseTurn(&G));	


	printf("Testing Complete\n");
	return 0;


}

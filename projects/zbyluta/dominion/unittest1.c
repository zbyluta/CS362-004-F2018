/*-------------------------------------------
 * unit test 1 for 
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

	printf("TESTING isGameOver():\n");

	memset(&G, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);
	G.handCount[p] = handCount;
	gameOver = isGameOver(&G);
	printf("isGameOver = %d, expected = 0\n", gameOver);
	G.supplyCount[adventurer] = 0;
	G.supplyCount[council_room] = 0;
	G.supplyCount[duchy] = 0;
	gameOver = isGameOver(&G);
	printf("isGameOver = %d, expected = 1\n", gameOver);
	
	G.supplyCount[duchy] = 5;
	gameOver = isGameOver(&G);
	printf("isGameOver = %d, expected = 0 \n", gameOver);
	


	G.supplyCount[province] = 0;
	gameOver = isGameOver(&G);
	printf("isGameOver = %d, expected = 1\n", gameOver);
	
	printf("All tests passed!\n");
	return 0;


}

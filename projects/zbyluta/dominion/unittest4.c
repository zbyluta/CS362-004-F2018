/*-------------------------------------------
 * unit test 4 for supplyCount() function
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

	printf("---------TESTING supplyCount():-----------\n");

	memset(&G, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);
	G.handCount[p] = handCount;
	
	printf("numAdventurer = %d, expected = 10\n", supplyCount(adventurer, &G));
	printf("numCouncil_Room = %d, expected = 10\n", supplyCount(council_room, &G));
	printf("numfeast = %d, expected = 10\n", supplyCount(feast, &G));
	printf("numGardens = %d, expected = 12\n", supplyCount(gardens, &G));
	printf("numMine = %d, expected = 10\n", supplyCount(mine, &G));
	printf("numRemodel = %d, expected = 10\n", supplyCount(remodel, &G));
	printf("numSmithy = %d, expected = 10\n", supplyCount(smithy, &G));
	printf("numVillage = %d, expected = 10\n", supplyCount(village, &G));
	G.supplyCount[adventurer] = 7;
	G.supplyCount[village] = 5;
	G.supplyCount[smithy] = 8;
	printf("-----------------------\n");
	printf("numAdventurer = %d, expected = 7\n", supplyCount(adventurer, &G));
	printf("numCouncil_Room = %d, expected = 10\n", supplyCount(council_room, &G));
	printf("numfeast = %d, expected = 10\n", supplyCount(feast, &G));
	printf("numGardens = %d, expected = 10\n", supplyCount(gardens, &G));
	printf("numMine = %d, expected = 10\n", supplyCount(mine, &G));
	printf("numRemodel = %d, expected = 10\n", supplyCount(remodel, &G));
	printf("numSmithy = %d, expected = 8\n", supplyCount(smithy, &G));
	printf("numVillage = %d, expected = 5\n", supplyCount(village, &G));	


	printf("---------Testing Complete-------------\n");
	return 0;


}

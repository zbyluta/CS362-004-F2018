/******************************************
 * unit test for village card
 *
 * ****************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){
	int r;
	int seed = 200;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int numPlayer = 2;
	int thisPlayer = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState G, testG;

	r = initializeGame(numPlayer, k, seed, &G);
	printf("----------------Testing Village Card---------------\n");
 	
	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("played card count = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount );
	printf("number of actions = %d, expected = %d\n", testG.numActions, G.numActions + 2);


	printf("\nTesting Complete\n");

}

/******************************************
 * unit test for smithy card
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
	printf("----------------Testing Smithy Card---------------\n");
	
	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 3 - 1);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 3);
	printf("played card count = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + 1);

	printf("SUCCESS: Testing Complete\n");
	printf("---------------------------------------------------\n");

}

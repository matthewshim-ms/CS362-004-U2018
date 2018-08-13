/* -----------------------------------------------------------------------
 * Random test for adventurerEffect()
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

void assertTrue(int a, int b, int *flag) {
  if (a == b) {
    printf("PASS");
  } else {
    printf("FAIL");
    *flag = 1;
  }
  printf(" -- expected %d, got %d\n", a, b);
}

int main (int argc, char** argv) {
  int numPlayers;
  struct gameState G;
  int k[10] = {adventurer, gardens, feast, village, minion, mine, cutpurse,
               great_hall, baron, smithy};
  srand(time(0));
  int randomSeed;
  int i;
  int j;
  int r;
  int drawntreasure;
  int cardDrawn;
  int temphand[MAX_HAND];
  int value1;
  int value2;
  int z = 0;
  int flag = 0;

  printf("Random testing for adventurerEffect():\n\n");

  randomSeed = rand();

  numPlayers = rand() % 3 + 2;
  printf("Randomizing number of players: %d\n\n", numPlayers);

  r = initializeGame(numPlayers, k, randomSeed, &G);

  if (r == -1) {
    printf("Game initialization failed -- unable to test adventurerEffect()!\n");
    return 1;
  }

  printf("Randomizing deck counts, hand counts, and discard counts\n\n");
  for (i = 0; i < numPlayers; i++) {
    G.deckCount[i] = rand() % 100;
    G.handCount[i] = rand() % 100;
    G.discardCount[i] = rand() % 100;
    printf("Starting deck count for player %d: %d\n", i+1, G.deckCount[i]);
    printf("Starting hand count for player %d: %d\n", i+1, G.handCount[i]);
    printf("Starting discard count for player %d: %d\n", i+1, G.discardCount[i]);
  }
  
  printf("\nEach player will play an adventurer.\nTesting one at a time:\n");

  for (i = 0; i < numPlayers; i++) {
    G.whoseTurn = i;
    value1 = G.handCount[i] + 2;
    value2 = G.deckCount[i] + G.discardCount[i] - 2;
    j = adventurerEffect(drawntreasure, &G, i, cardDrawn, temphand, z);
    if (j != 0) {
      flag = 1;
      printf("ERROR -- adventurerEffect() did not return correctly\n");
    }
    printf("\nPlayer %d now has %d cards in hand\n", i+1, G.handCount[i]);
    assertTrue(value1, G.handCount[i], &flag);
    printf("Player %d now has %d cards in deck and discard\n", i+1, G.deckCount[i] + G.discardCount[i]);
    assertTrue(value2, G.deckCount[i] + G.discardCount[i], &flag);
  }

  if (flag == 0) {
    printf("\nAll tests passed!\n\n");
  } else {
    printf("\nERROR -- TESTS FAILED!\n\n");
  }

  return 0;
}

/* -----------------------------------------------------------------------
 * Unit test for smithyEffect()
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
  int handPos;
  int value1;
  int value2;
  int value3;
  int flag = 0;

  printf("Unit testing for smithyEffect():\n\n");

  randomSeed = rand();

  for (numPlayers = 2; numPlayers < 5; numPlayers++) {
    printf("Now testing with %d players\n\n", numPlayers);

    r = initializeGame(numPlayers, k, randomSeed, &G);

    if (r == -1) {
      printf("Game initialization failed -- unable to test smithyEffect()!\n");
      return 1;
    }

    printf("Setting deck, hand, and discard counts to 50\n");
    for (i = 0; i < numPlayers; i++) {
      G.deckCount[i] = 50;
      G.handCount[i] = 50;
      G.discardCount[i] = 50;
    }
    
    printf("\nEach player will play a smithy.\nTesting one at a time:\n");

    for (i = 0; i < numPlayers; i++) {
      value1 = G.deckCount[i] - 3;
      value2 = G.handCount[i] + 3;
      value3 = G.discardCount[i];
      j = smithyEffect(i, &G, handPos);
      if (j != 0) {
        flag = 1;
        printf("ERROR -- smithyEffect() did not return correctly\n");
      }
      printf("\nPlayer %d now has %d cards in deck\n", i+1, G.deckCount[i]);
      assertTrue(value1, G.deckCount[i], &flag);
      printf("\nPlayer %d now has %d cards in hand\n", i+1, G.handCount[i]);
      assertTrue(value2, G.handCount[i], &flag);
      printf("\nPlayer %d still has %d cards in discard\n", i+1, G.discardCount[i]);
      assertTrue(value3, G.discardCount[i], &flag);
    }

    printf("Setting deck counts to 0\nSetting hand and discard counts to 50\n");
    for (i = 0; i < numPlayers; i++) {
      G.deckCount[i] = 0;
      G.handCount[i] = 50;
      G.discardCount[i] = 50;
    }
    
    printf("\nEach player will play another smithy.\nTesting one at a time:\n");

    for (i = 0; i < numPlayers; i++) {
      value1 = G.deckCount[i] - 3;
      value2 = G.handCount[i] + 3;
      value3 = G.discardCount[i];
      j = smithyEffect(i, &G, handPos);
      if (j != 0) {
        flag = 1;
        printf("ERROR -- smithyEffect() did not return correctly\n");
      }
      printf("\nPlayer %d now has %d cards in deck\n", i+1, G.deckCount[i]);
      assertTrue(value1, G.deckCount[i], &flag);
      printf("\nPlayer %d now has %d cards in hand\n", i+1, G.handCount[i]);
      assertTrue(value2, G.handCount[i], &flag);
      printf("\nPlayer %d still has %d cards in discard\n", i+1, G.discardCount[i]);
      assertTrue(value3, G.discardCount[i], &flag);
    }
  }

  if (flag == 0) {
    printf("\nAll tests passed!\n\n");
  } else {
    printf("\nERROR -- TESTS FAILED!\n\n");
  }

  return 0;
}

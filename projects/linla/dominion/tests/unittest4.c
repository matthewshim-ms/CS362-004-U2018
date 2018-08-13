/* -----------------------------------------------------------------------
 * Unit test for numHandCards()
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
  int i;
  int j;
  int flag = 0;

  printf("Unit testing for numHandCards():\n\n");

  for (numPlayers = 2; numPlayers < 5; numPlayers++) {
    printf("Now testing with %d players\n\n", numPlayers);

    for (i = 0; i < numPlayers; i++) {
      G.whoseTurn = i;
      for (j = 0; j < 20; j++) {
        G.handCount[i] = j;
        printf("Player %d has %d cards in hand\n", i+1, j);
        assertTrue(j, numHandCards(&G), &flag);
      }
    }
  }

  if (flag == 0) {
    printf("\nAll tests passed!\n\n");
  } else {
    printf("\nERROR -- TESTS FAILED!\n\n");
  }

  return 0;
}

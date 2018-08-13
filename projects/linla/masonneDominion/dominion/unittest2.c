/* -----------------------------------------------------------------------
 * Unit test for isGameOver()
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
  int r;
  int flag = 0;

  printf("Unit testing for isGameOver():\n\n");

  randomSeed = rand();

  for (numPlayers = 2; numPlayers < 5; numPlayers++) {
    printf("Now testing with %d players\n\n", numPlayers);

    r = initializeGame(numPlayers, k, randomSeed, &G);

    if (r == -1) {
      printf("Game initialization failed -- unable to test isGameOver()!\n");
      return 1;
    }
    
    printf("Setting supply of province cards to 0\n");
    G.supplyCount[province] = 0;
    assertTrue(1, isGameOver(&G), &flag);
    
    printf("Setting supply of province cards to 12\n");
    G.supplyCount[province] = 12;
    assertTrue(0, isGameOver(&G), &flag);
    
    printf("Setting supply of 2 kingdom cards to 0\n");
    G.supplyCount[adventurer] = 0;
    G.supplyCount[great_hall] = 0;
    assertTrue(0, isGameOver(&G), &flag);

    printf("Setting supply of one more card to 0\n");
    G.supplyCount[duchy] = 0;
    assertTrue(1, isGameOver(&G), &flag);

    printf("Setting supply of that card to 12\n");
    G.supplyCount[duchy] = 12;
    assertTrue(0, isGameOver(&G), &flag);
  }

  if (flag == 0) {
    printf("\nAll tests passed!\n\n");
  } else {
    printf("\nERROR -- TESTS FAILED!\n\n");
  }

  return 0;
}

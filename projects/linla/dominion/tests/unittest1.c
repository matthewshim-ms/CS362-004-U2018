/* -----------------------------------------------------------------------
 * Unit test for getCost()
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
  int value;
  int flag = 0;

  printf("Unit testing for getCost():\n\n");

  randomSeed = rand();

  for (numPlayers = 2; numPlayers < 5; numPlayers++) {
    printf("Now testing with %d players\n\n", numPlayers);

    r = initializeGame(numPlayers, k, randomSeed, &G);

    if (r == -1) {
      printf("Game initialization failed -- unable to test getCost()!\n");
      return 1;
    }
    
    printf("Getting the cost of each card.\nTesting one at a time:\n\n");

    for (i = 0; i < 10; i++) {
      value = getCost(k[i]);
      switch(k[i]) {
        case adventurer:
          printf("Adventurer costs %d coins\n", value);
          assertTrue(6, value, &flag);
          break;
        case gardens:
          printf("Gardens costs %d coins\n", value);
          assertTrue(4, value, &flag);
          break;
        case feast:
          printf("Feast costs %d coins\n", value);
          assertTrue(4, value, &flag);
          break;
        case village:
          printf("Village costs %d coins\n", value);
          assertTrue(3, value, &flag);
          break;
        case minion:
          printf("Minion costs %d coins\n", value);
          assertTrue(5, value, &flag);
          break;
        case mine:
          printf("Mine costs %d coins\n", value);
          assertTrue(5, value, &flag);
          break;
        case cutpurse:
          printf("Cutpurse costs %d coins\n", value);
          assertTrue(4, value, &flag);
          break;
        case great_hall:
          printf("Great Hall costs %d coins\n", value);
          assertTrue(3, value, &flag);
          break;
        case baron:
          printf("Baron costs %d coins\n", value);
          assertTrue(4, value, &flag);
          break;
        case smithy:
          printf("Smithy costs %d coins\n", value);
          assertTrue(4, value, &flag);
          break;
        default:
          printf("Not a kingdom card\n");
          assertTrue(-1, value, &flag);
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

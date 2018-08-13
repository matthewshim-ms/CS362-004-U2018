/* -----------------------------------------------------------------------
 * Random test for baronEffect()
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
  int value1;
  int value2;
  int value3;
  int value4;
  int choice1;
  int flag = 0;

  printf("Random testing for baronEffect():\n\n");

  randomSeed = rand();

  numPlayers = rand() % 3 + 2;
  printf("Randomizing number of players: %d\n\n", numPlayers);

  r = initializeGame(numPlayers, k, randomSeed, &G);

  if (r == -1) {
    printf("Game initialization failed -- unable to test baronEffect()!\n");
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
  
  printf("\nEach player will play a baron.\nTesting one at a time:\n");

  for (i = 0; i < numPlayers; i++) {
    G.whoseTurn = i;
    printf("\nRandomizing number of buys, coins, and player choice\n");
    G.numActions = rand() % 30;
    G.coins = rand() % 50;
    choice1 = rand() % 1000;
    if (choice1 > 350) {
      choice1 = 1;
    } else {
      choice1 = -1;
    }
    printf("Randomizing supply count of estates\n");
    G.supplyCount[estate] = rand() % 30;
    value1 = G.numBuys + 1;
    value2 = G.coins + 4;
    value3 = G.discardCount[i] + 1;
    value4 = G.handCount[i] - 1;
    j = baronEffect(&G, choice1, i);
    if (j != 0) {
      flag = 1;
      printf("ERROR -- baronEffect() did not return correctly\n");
    }
    printf("\nPlayer %d now has %d buys\n", i+1, G.numBuys);
    assertTrue(value1, G.numBuys, &flag);

    if (G.coins == value2) {
      printf("\nPlayer %d discarded an estate and now has %d coins\n", i+1, G.coins);
      assertTrue(value2, G.coins, &flag);
      printf("Player %d now has %d cards in discard\n", i+1, G.discardCount[i]);
      assertTrue(value3, G.discardCount[i], &flag);
      printf("Player %d now has %d cards in hand\n", i+1, G.handCount[i]);
      assertTrue(value4, G.handCount[i], &flag);
    } else if (G.discardCount[i] == value3) {
      printf("\nPlayer %d gained an estate and now has %d cards in discard\n", i+1, G.discardCount[i]);
      assertTrue(value3, G.discardCount[i], &flag);
      printf("Player %d still has %d coins\n", i+1, G.coins);
      assertTrue(value2-4, G.coins, &flag);
      printf("Player %d still has %d cards in hand\n", i+1, G.handCount[i]);
      assertTrue(value4+1, G.handCount[i], &flag);
    } else if (G.coins == value2-4) {
      printf("\nNo more estates left");
      assertTrue(0, G.supplyCount[estate], &flag);
      printf("Player %d still has %d coins\n", i+1, G.coins);
      assertTrue(value2-4, G.coins, &flag);
      printf("Player %d still has %d cards in discard\n", i+1, G.discardCount[i]);
      assertTrue(value3-1, G.discardCount[i], &flag);
      printf("Player %d still has %d cards in hand\n", i+1, G.handCount[i]);
      assertTrue(value4+1, G.handCount[i], &flag);
    }
  }

  if (flag == 0) {
    printf("\nAll tests passed!\n\n");
  } else {
    printf("\nERROR -- TESTS FAILED!\n\n");
  }

  return 0;
}

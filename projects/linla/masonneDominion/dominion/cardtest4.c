/* -----------------------------------------------------------------------
 * Unit test for case great_hall in cardEffect()
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
  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int bonus = 0;
  int flag = 0;
  
  printf("Unit testing for greatHallEffect():\n\n");

  randomSeed = rand();

  for (numPlayers = 2; numPlayers < 5; numPlayers++) {
    printf("Now testing with %d players\n\n", numPlayers);

    r = initializeGame(numPlayers, k, randomSeed, &G);

    if (r == -1) {
      printf("Game initialization failed -- unable to test greatHallEffect()!\n");
      return 1;
    }

    printf("Setting deck, hand, and discard counts to 50\n");
    for (i = 0; i < numPlayers; i++) {
      G.deckCount[i] = 50;
      G.handCount[i] = 50;
      G.discardCount[i] = 50;
    }
    
    printf("\nEach player will play a great hall.\nTesting one at a time:\n");

    for (i = 0; i < numPlayers; i++) {
      G.whoseTurn = i;
      printf("Setting number of actions and hand position to 0");
      G.numActions = 0;
      handPos = 0;
      value1 = G.numActions + 1;
      value2 = G.deckCount[i] - 1;
      value3 = G.handCount[i] + 1;
      j = cardEffect(great_hall, choice1, choice2, choice3, &G, handPos, &bonus);
      if (j != 0) {
        flag = 1;
        printf("ERROR -- greatHallEffect() did not return correctly\n");
      }
      printf("\nPlayer %d now has %d actions\n", i+1, G.numActions);
      assertTrue(value1, G.numActions, &flag);
      printf("Player %d now has %d cards in deck\n", i+1, G.deckCount[i]);
      assertTrue(value2, G.deckCount[i], &flag);
      printf("Player %d now has %d cards in hand\n", i+1, G.handCount[i]);
      assertTrue(value3, G.handCount[i], &flag);
    }

    printf("Setting deck, hand, and discard counts to 50\n");
    for (i = 0; i < numPlayers; i++) {
      G.deckCount[i] = 50;
      G.handCount[i] = 50;
      G.discardCount[i] = 50;
    }
    
    printf("\nEach player will play another great hall.\nTesting one at a time:\n");

    for (i = 0; i < numPlayers; i++) {
      G.whoseTurn = i;
      printf("Setting number of actions to 20 and hand position to 49");
      G.numActions = 20;
      handPos = 49;
      value1 = G.numActions + 1;
      value2 = G.deckCount[i] - 1;
      value3 = G.handCount[i] + 1;
      j = cardEffect(great_hall, choice1, choice2, choice3, &G, handPos, &bonus);
      if (j != 0) {
        flag = 1;
        printf("ERROR -- greatHallEffect() did not return correctly\n");
      }
      printf("\nPlayer %d now has %d actions\n", i+1, G.numActions);
      assertTrue(value1, G.numActions, &flag);
      printf("Player %d now has %d cards in deck\n", i+1, G.deckCount[i]);
      assertTrue(value2, G.deckCount[i], &flag);
      printf("Player %d now has %d cards in hand\n", i+1, G.handCount[i]);
      assertTrue(value3, G.handCount[i], &flag);
    }

    printf("Setting deck count to 0\nSetting hand and discard counts to 50\n");
    for (i = 0; i < numPlayers; i++) {
      G.deckCount[i] = 0;
      G.handCount[i] = 50;
      G.discardCount[i] = 50;
    }
    
    printf("\nEach player will play a great hall.\nTesting one at a time:\n");

    for (i = 0; i < numPlayers; i++) {
      G.whoseTurn = i;
      printf("Setting number of actions and hand position to 0");
      G.numActions = 0;
      handPos = 0;
      value1 = G.numActions + 1;
      value2 = G.deckCount[i] - 1;
      value3 = G.handCount[i] + 1;
      j = cardEffect(great_hall, choice1, choice2, choice3, &G, handPos, &bonus);
      if (j != 0) {
        flag = 1;
        printf("ERROR -- greatHallEffect() did not return correctly\n");
      }
      printf("\nPlayer %d now has %d actions\n", i+1, G.numActions);
      assertTrue(value1, G.numActions, &flag);
      printf("Player %d now has %d cards in deck\n", i+1, G.deckCount[i]);
      assertTrue(value2, G.deckCount[i], &flag);
      printf("Player %d now has %d cards in hand\n", i+1, G.handCount[i]);
      assertTrue(value3, G.handCount[i], &flag);
    }

    printf("Setting deck count to 0\nSetting hand and discard counts to 50\n");
    for (i = 0; i < numPlayers; i++) {
      G.deckCount[i] = 0;
      G.handCount[i] = 50;
      G.discardCount[i] = 50;
    }
    
    printf("\nEach player will play another great hall.\nTesting one at a time:\n");

    for (i = 0; i < numPlayers; i++) {
      G.whoseTurn = i;
      printf("Setting number of actions to 20 and hand position to 49");
      G.numActions = 20;
      handPos = 49;
      value1 = G.numActions + 1;
      value2 = G.deckCount[i] - 1;
      value3 = G.handCount[i] + 1;
      j = cardEffect(great_hall, choice1, choice2, choice3, &G, handPos, &bonus);
      if (j != 0) {
        flag = 1;
        printf("ERROR -- greatHallEffect() did not return correctly\n");
      }
      printf("\nPlayer %d now has %d actions\n", i+1, G.numActions);
      assertTrue(value1, G.numActions, &flag);
      printf("Player %d now has %d cards in deck\n", i+1, G.deckCount[i]);
      assertTrue(value2, G.deckCount[i], &flag);
      printf("Player %d now has %d cards in hand\n", i+1, G.handCount[i]);
      assertTrue(value3, G.handCount[i], &flag);
    }
  }

  if (flag == 0) {
    printf("\nAll tests passed!\n\n");
  } else {
    printf("\nERROR -- TESTS FAILED!\n\n");
  }

  return 0;
}

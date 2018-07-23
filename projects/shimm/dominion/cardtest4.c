#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int test_failures = 0;

void assertTrue(int a, int b){
    if (a == b){
        printf("TEST PASSED \n");
    }else{
        printf("TEST FAILED \n");
        test_failures++;
    }
}

// ** Village Card Tests

int main()
{
    struct gameState *state = newGame();
    int num_players = 2;
    int rand_seed = 1000;
    int player1 = 0;
    int player2 = 0;
    int hand_position = 0;

    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;

    int kingdom[10] = {
        adventurer,
        smithy,
        gardens,
        embargo,
        village,
        baron,
        sea_hag,
        great_hall,
        mine,
        feast
    }

    int status = initializeGame(num_players, kingdom, rand_seed, state);
    my_assert(status == 0, "Game initialized properly?");

    printf("TESTING VILLAGE CARD\n");

    struct gameState state_new;
    struct gameState state_init;

    memset(&state_new, 23, sizeof(struct, gameState));
    memset(&state_init, 23, sizeof(struct, gameState));
    initializeGame(num_players, kingdom, rand_seed, &state_new);
    memcpy(&state_init, &state_new, sizeof(Struct, gameState));

    cardEffect(village, choice1, choice2, choice3, &state_new, handpos, &bonus);

    printf("\nPlayer 1 gains 1 card\n");
    assertTrue(state_new.handCount[player1], state_init.handCount[player1]);

    printf("\nPlayer 1 draws a card\n");
    assertTrue(state_new.deckCount[player1], state_init.deckCount[player1] - 1);

    printf("\n Player 1 gains 2 actions \n");
    assertTrue(state_new.numActions, state_init.numActions + 2);


    // Ensure other cards are still in valid pile state after card actions have taken effect
    printf("Counting Estate Cards \n");
    assertTrue(state.supplyCount[estate],stateOriginal.supplyCount[estate]);

    printf("Counting Province Cards \n");
    assertTrue(state.supplyCount[province],stateOriginal.supplyCount[province]);

    printf("Counting Duchy Cards \n");
    assertTrue(state.supplyCount[duchy],stateOriginal.supplyCount[duchy]);

    // Ensure hand count is still valid
    printf("Hand Count\n");
    assertTrue(state.handCount[player1],stateOriginal.handCount[player1]);
    printf("Deck Count\n");
    assertTrue(state.deckCount[player1],stateOriginal.deckCount[player1]);
    printf("\n Player1 Hand CHECK \n");

    if(test_failures > 0){
        printf("\n *** WARNING - Test Failures\n");
        printf("Failure Count: %d\n", test_failures);
    }else{
        printf(" !!! ALL TESTS PASSED\n\n");
    }
    return 0;
}
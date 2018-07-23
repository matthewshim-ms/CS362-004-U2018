#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "assert.h"

int test_failures = 0;

void assertTrue(int a, int b){
    if (a == b){
        printf("TEST PASSED \n");
    }else{
        printf("TEST FAILED \n");
        test_failures++;
    }
}

// ** Smithy Card Tests

int main()
{
    struct gameState *state = newGame();
    int num_players = 2;
    int rand_seed = 1000;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;

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


    for(int i = 0; i < num_players; i++){
        state->whoseTurn = i;
        state->handCount[i] = 1;
        state->hand[i][0] = smithy;
        int result = cardEffect(smithy, choice1, choice2, choice3, state, 0, NULL);
        assert(result == 0, "Smithy Card Test");
    }

    struct gameState state_new;
    struct gameState state_init;

    memset(&state_new, 23, sizeof(struct, gameState));
    memset(&state_init, 23, sizeof(struct, gameState));
    initializeGame(num_players, kingdom, rand_seed, &state_new);
    memcpy(&state_init, &state_new, sizeof(Struct, gameState));


    if(test_failures > 0){
        printf("\n *** WARNING - Test Failures\n");
        printf("Failure Count: %d\n", test_failures);
    }else{
        printf(" !!! ALL TESTS PASSED\n\n");
    }

    return 0;
}
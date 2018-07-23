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

// TESTING isGameOver()

int main()
{
    printf("Testing ----> isGameOver() function\n");

    struct gameState *state;
    int num_players = 2;
    int rand_seed = 1000;

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

    // Test game over now
    struct gameState newState;
    printf("TESTING -----> isGameOver()\n");


    if(test_failures > 0){
        printf("\n *** WARNING - Test Failures\n");
        printf("Failure Count: %d\n", test_failures);
    }else{
        printf(" !!! ALL TESTS PASSED\n\n");
    }
}
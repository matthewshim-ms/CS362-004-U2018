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

    struct gameState state;
    struct gameState state_init;
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

    memset(&state, 23, sizeof(struct gameState));
    initializeGame(num_players, kingdom, rand_seed, &state);
    
    state.supplyCount[province] = 0;
    printf("\n Province cards empty \n");
    assertTrue(isGameOver(&state),1);
  
    state.supplyCount[province] = 1;
    state.supplyCount[0] = 0;
    state.supplyCount[1] = 0;
    state.supplyCount[2] = 0;

    printf("\n Supply cards are empty \n");
    assertTrue(isGameOver(&state), 1);

    if(test_failures > 0){
        printf("\n *** WARNING - Test Failures\n");
        printf("Failure Count: %d\n", test_failures);
    }else{
        printf(" !!! ALL TESTS PASSED\n\n");
    }

    return 0;
}
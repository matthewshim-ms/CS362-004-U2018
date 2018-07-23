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

// ** ADVENTURE CARD TESTS

int main(int argc, char** argv)
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

    int status = initializeGame(num_players, kingdom, rand_seed, g);
    my_assert(status == 0, "Game Stat initialized?");

    // Test
    buyCard(smithy, state);
    int result = cardEffect(adventurer, choice1, choice2, choice3, state, 0, NULL);
    my_assert(result == 0, "Testing adventurer card");


    if(test_failures > 0){
        printf("\n *** WARNING - Test Failures\n");
        printf("Failure Count: %d\n", test_failures);
    }else{
        printf(" !!! ALL TESTS PASSED\n\n");
    }

    return 0;
}
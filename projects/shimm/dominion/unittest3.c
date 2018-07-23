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

// TESTING gainCard()

int main()
{
    printf("TESTING ----> gainCard() function \n");

    struct gameState state;
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

    memset(&state,23,sizeof(struct gameState));
    initializeGame(2, kingdom, seed, &state);

    printf("\nGold supply pile is empty\n");
    state.supplyCount[gold] = 0;
    assertTrue(gainCard(gold, &state, 0, 0),-1);
    state.supplyCount[gold] = 30;

    // Add card to Deck
    printf("\nAdd card to deck\n");
    int deckCount = state.deckCount[0];
    gainCard(gold, &state, 1,0);
    assertTrue(deckCount+1, state.deckCount[0]);

    // Add Card to Hand
    printf("\n Adding card: +1 card to hand \n");
    int handCount = state.handCount[0];
    gainCard(gold, &state, 2, 0);
    assertTrue(handCount + 1, state.handCount[0]);

    // Discard Card, move to discard
    printf("\n Removing card: -1 card to discard pile\n");
    int discardCount = state.discardCount[0];
    gainCard(gold, &state, 0, 0);
    assertTrue(discardCount+1,state.discardCount[0]);

    printf("\n Subtract 1 from Gold \n");
    int goldSupply = state.supplyCount[gold];
    gainCard(gold, &state, 0, 0);
    assertTrue(goldSupply - 1,state.supplyCount[gold]);

    if(test_failures > 0){
        printf("\n *** WARNING - Test Failures\n");
        printf("Failure Count: %d\n", test_failures);
    }else{
        printf(" !!! ALL TESTS PASSED\n\n");
    }

    return 0;
}
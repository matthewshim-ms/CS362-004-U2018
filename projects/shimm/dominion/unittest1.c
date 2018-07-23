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

// TESTING UPDATE COINS

int main()
{
    printf("TESTING ----> updateCoins()");

    int num_players = 2;
    int rand_seed = 1000;
    struct gameState state;
    int bonus = 1;
    int handCount = 0;

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

    int copper[MAX_HAND];
    int silver[MAX_HAND];
    int gold[MAX_HAND];

    for(int i = 0; i < MAX_HAND; i++){
        copper[i] = copper;
        silver[i] = silver;
        gold[i] = gold;
    }


    for (handCount = 0; handCount <= 5; handCount +=5) {

        printf("\nTreasure cards: %d\n",handCount);
        printf("Bonus: %d\n", bonus);

        memset(&state,23,sizeof(struct gameState));
        b = initializeGame(numbPlayers, k, seed, &state);
        state.handCount[player] = handCount;

        // Test Coppers
        memcpy(state.hand[player],coppers,sizeof(int)*handCount);
        updateCoins(player,&state,bonus);
        printf("\n Copper Count \n");
        printf("Expected: %d\n", handCount*1 + bonus);        
        printf("Actual: %d\n",state.coins);
        assertTrue(state.coins,handCount*1+bonus);

        // Test Silvers
        memcpy(state.hand[player],silvers,sizeof(int)*handCount);
        updateCoins(player,&state,bonus);
        printf("\n Silver Count \n");
        printf("Expected: %d\n", handCount*2 + bonus);
        printf("Actual: %d\n", state.coins);
        assertTrue(state.coins,handCount*2+bonus);

        // Test Gold
        memcpy(state.hand[player],golds,sizeof(int)*handCount);
        updateCoins(player,&state,bonus);
        printf("\n Gold Count \n");
        printf("Expected: %d\n",handCount*3 + bonus);
        printf("Actual: %d\n",state.coins);
        assertTrue(state.coins,handCount*3 + bonus);

        bonus = bonus + 2;
    }

    if(test_failures > 0){
        printf("\n *** WARNING - Test Failures\n");
        printf("Failure Count: %d\n", test_failures);
    }else{
        printf(" !!! ALL TESTS PASSED\n\n");
    }
}
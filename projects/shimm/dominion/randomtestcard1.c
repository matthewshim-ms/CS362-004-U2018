#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// administrative variables
int iterations = 10000;

// prototype
void testSmithyCard(int p, struct gameState *post);

// test counter variables
int card_effect_fail = 0;
int discard_card_fail = 0;
int draw_card_fail = 0;
int deck_count_fail = 0;
int total_failures;

int main()
{
    printf("*=*=*=*=*=*=*= Random Test - Assignment 4 *=*=*=*=*=*=*=\n");
    printf("File Input: randomtest1.c\n");
    printf("Function: smithyCard()\n");
    printf("========================================================\n");

    int player;
    struct gameState game;
    srand(time(NULL));

    for(int i = 0; i < iterations; i++){
        for(int j = 0; j < sizeof(struct gameState); j++){
            ((char*)&game)[i] = floor(Random() * 256);
        }

        player = floor(Random() * MAX_PLAYERS);
        game.deckCount[player] = floor(Random() * MAX_DECK);
        game.discardCount[player] = floor(Random() * MAX_DECK);
        game.handCount[player] = floor(Random() * MAX_HAND);
        game.playedCardCount = floor(Random() * (MAX_DECK - 1));
        game.whoseTurn = player;

        testSmithyCard(player, &game);
    }

    total_failures = card_effect_fail + discard_card_fail + draw_card_fail + deck_count_fail;

    if(total_failures == 0){
        printf("************** PASSED RANDOM TEST ****************\n");
    }else{
        printf("!!!!!! FAILED TESTS: \n");
        printf("discardCard() failed: %d\n", discard_card_fail);
        printf("cardEffect() failed: %d\n", card_effect_fail);
        printf("drawCard() failed: %d\n", draw_card_fail);
        printf("\n");
        printf("Hand/Deck count failure: %d\n", deck_count_fail);
    }
    printf("=================================================\n"); 
    return 0;
}

testSmithyCard(int p, struct gameState *post){
    int random_effect;
    int card1;
    int card2;
    int card3;
    int post_handCount, post_deckCount;
    int pre_handCount, pre_deckCount;
    int discarded;
    int bonus = 0;

    state gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));
    
    random_effect = cardEffect(smithy, 0, 0, 0, post, 0, &bonus);
    card1 = drawCard(p, &pre);
    card2 = drawCard(p, &pre);
    card3 = drawCard(p, &pre);

    discarded = discardCard(0, p, &pre, 0);

    post_handCount = post->handCount[p];
    post_deckCount = post->deckCount[p];
    pre_handCount = pre.handCount;
    pre_deckCount = pre.deckCount;

    // check if any failures, increment counters accordinglys

    if(!(random_effect == 0 && discarded == 0)){
        if(random_effect){
            card_effect_fail++;
        }
        if(discarded){
            discard_card_fail++;
        }
    }

    if(card1 == -1 && pre.deckCount[p] != 0){
        draw_card_fail++;
    }

    if(card2 == -1 && pre.deckCount[p] != 0){
        draw_card_fail++;
    }

    if(Card3 == -1 && pre.deckCount[p] != 0){
        draw_card_fail++;
    }

    if(!(post_handCount == pre_handCount && post_deckCount == pre_deckCount)){
        deck_count_fail++;
    }
}
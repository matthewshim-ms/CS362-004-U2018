#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

// Testing variables
int card_effect_fail = 0;
int shuffle_fail = 0;
int draw_card_fail = 0;
int deck_count_fail = 0;
int treasure_count_fail = 0;
int total_fail; 

// method prototype
void testAdventurerCard(int p, struct gameState *post);

// Administrative variables
int test_iterations = 10000;

int main()
{
    printf("*=*=*=*=*=*=*= Random Test - Assignment 4 *=*=*=*=*=*=*=\n");
    printf("File Input: randomtestadventurer.c\n");
    printf("Function: adventurerCard()\n");
    printf("========================================================\n");

    int treasures[] = { copper, silver, gold };
    int num_treasures;
    int player;
    struct gameState game; 

    int minimum_cards = 3;

    srand(time(NULL));

    for(int i = 0; i < iterations; i++){
        for(int j = 0; j < sizeof(struct gameState); j++){
            ((char*)&G)[j] = floor(Random() * 256);
        }
    }

    player = floor(Random() * MAX_PLAYERS);
    game.deckCount[player] = floor(Random() * ((MAX_DECK - minimum_cards) + 1) + minimum_cards);
    num_treasures = floor(Random() * ((game.deckCount[player - minimum_cards]) + 1) + minimum_cards);

    for(int i = 0; i < num_treasures; i++){
        game.deck[player][i] = treasures[rand() % 3];
    }
    game.discardCount[player] = 0;
    game.handCount[player] = floor(Random()* ((MAX_HAND - minimum_cards) + 1) + minimum_cards);
    game.whoseTurn = player;

    testAdventurerCard(player, &game);
    total_fail = card_effect_fail + draw_card_fail + shuffle_fail + deck_count_fail + treasure_count_fail;

    if(total_fail == 0){
        printf("************** PASSED RANDOM TEST ****************\n");
    }else{
        printf("!!!!!! FAILED TESTS: \n");
        printf("shuffle() failed: %d\n", shuffle_fail);
        printf("cardEffect() failed: %d\n", card_effect_fail);
        printf("drawCard() failed: %d\n", draw_card_fail);
        printf("\n");
        printf("Treasure Count failures: %d\n", treasure_count_fail);
        printf("Deck Count failure: %d\n", deck_count_fail);
    }

    printf("=================================================\n");
    return 0;
}


void testAdventurerCard(int p, struct gameState *post){
    int post_treasureCount = 0;
    int pre_treasureCount = 0;

    int hand_temp[MAX_HAND];
    int drawn_treasure = 0;

    struct gameState preState;
    int cardDrawn;
    int card;
    int bonus, z = 0;

    int treasure;
    int randomEffect;
    int shuffle; 

    int post_handCount, post_deckCount, post_discardCount, pre_handCount, pre_deckCount, pre_discardCount;


    memcpy(&pre, post, sizeof(struct gameState));

    // card effect function is called with adventurercard
    randomEffect = cardEffect(adventurer, 0, 0, 0, post, 0, &bonus);

    if(randomEffect){
        card_effect_fail++;
    }

    while(drawn_treasure < 2)
    {
        if(pre.deckCount[p] < 1){
            shuffle = shuffle(p, &pre);

            if(shuffle == -1 && pre.deckCount[p] >= 1){
                shuffle_fail++;
            }
        }

        treasure = drawCard(p, &pre);
        if(treasure == -1 && pre.deckCount[p] != 0){
            draw_card_fail++;
        }

        cardDrawn = pre.hand[p][pre.handCount[p] -1];
        if(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
            drawn_treasure++;
        }else{
            hand_temp[z] = cardDrawn;
            pre.handCount[p]--;
            z++;
        }

    }

    while(z - 1 >= 0){
            pre.discard[p][pre.discardCount[p]++] = hand_temp[z - 1];
            z--;
        }

    // POST resolution game state treasure count 
    for(int i = 0; i < post->handCount[p]; i++){
        card = post->hand[p][i];
        if(card == copper || card == silver || card == gold){
            post_treasureCount++;
        }
    }

    // PRE resolution game state treasure count
    for(int i = 0; i < pre.handCount[p]; i++){
        card = pre.hand[p][i];
        if(card == copper || card == silver || card == gold){
            pre_treasureCount++;
        }
    }

    if(pre_treasureCount != post_treasureCount){
        treasure_count_fail++;
    }

    post_handCount = post->handCount[p];
    post_deckCount = post->deckCount[p];
    post_discardCount = post->discardCount[p];
    pre_handCount = pre.handCount[p];
    pre_deckCount = pre.deckCount[p];
    pre_discardCount = pre.discardCount[p];

    if(!(post_handCount == pre_handCount && post_deckCount == pre_deckCount && post_discardCount == pre_discardCount)){
        deck_count_fail++;
    }

}
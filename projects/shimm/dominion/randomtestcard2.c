#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// administrative variables
int iterations = 10000;

// test counter variables
int card_effect_fail = 0;
int discard_card_fail = 0;
int draw_card_fail = 0;
int deck_count_fail = 0;
int card_buy_fail = 0;
int other_player_fails = 0;

int total_failures;

// prototypes
void testCouncilRoomCard(int p, struct gameState *post);

int main()
{
    


    return 0;
}

testCouncilRoomCard(int p, struct gameState *post){
    
    int bonus = 0;
    int card1, card2, card3, card4, card5, card6;
    int random_card;
    int post_handCount, post_deckCount;
    int pre_handCount, pre_deckCount;
    struct gameState pre;
    
    memcpy(&pre, post, sizeof(struct gameState));

    card1 = drawCard(p, &pre);
    card2 = drawCard(p, &pre);
    card3 = drawCard(p, &pre);
    card4 = drawCard(p, &pre);

    random_card = cardEffect(council_room, 0, 0, 0, post, 0, &bonus);

    pre.numBuys++;

    for(int i = 0; i < pre.numPlayers; i++){
        if(i != p){
            card5 = drawCard(i, &pre);
            if(card5 == -1 && pre.deckCount[i] != 0){
                draw_card_fail++;
            }
        }
    }

    card6 = discardCard(0, p, &pre, 0);

    post_handCount = post->handCount[p];
    post_deckCount = post->deckCount[p];
    pre_handCount = pre.handCount[p];
    pre_deckCount = pre.deckCount[p];

    if(card1 == -1 && pre.deckCount[p]!= 0){
        draw_card_fail++;
    }
    if(card2 == -1 && pre.deckCount[p]!= 0){
        draw_card_fail++;
    }
    if(card3 == -1 && pre.deckCount[p]!= 0){
        draw_card_fail++;
    }
    if(card4 == -1 && pre.deckCount[p]!= 0){
        draw_card_fail++;
    }

    if(pre.numBuys != post->numBuys){
        card_buy_fail++;
    }
    
    if (!(random_card == 0 && card6 == 0)) {
        if (random_card) {
            card_effect_fail++;
        }
        if (card6) {
            discard_card_fail++;
        }
    }

    if (!(post_handCount == pre_handCount && post_deckCount == pre_deckCount)) {
        deck_count_fail++;
    }

    for (int i = 0; i < pre.numPlayers; i++) {
        if (i != p) {
            if (!(post->handCount[i] == pre.handCount[i] && post->deckCount[i] == pre.deckCount[i])) {
                other_player_fails++;
            }
        }
    }    
}
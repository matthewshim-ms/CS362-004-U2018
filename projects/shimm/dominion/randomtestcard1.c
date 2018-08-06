#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// prototype
void testSmithyCard(int p, struct gameState *post);

// test counter variables
int card_effect_fail = 0;
int discard_card_fail = 0;
int draw_card_fail = 0;
int deck_count_fail = 0;

int main()
{
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

    // 

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
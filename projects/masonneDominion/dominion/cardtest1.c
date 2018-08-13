/**
Name: Neale Mason
Date: 7/20/2018
Email: masonne@oregonstate.edu
Description: Here I test the smithy card
**/

//Includes are from the dominion.c file
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//following code borrows heavily from playdom.c for implementation
int main(){
 struct gameState G, H; //using 2 gamestates to keep track of "before card" and "after card"
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  printf ("Testing SMITHY: ");

//int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);
  initializeGame(2, k, 20, &G);

  int test_Result=1;

  int choice1=0, choice2=0, choice3=0;
  H=G;

  cardEffect(smithy,choice1, choice2, choice3, &G,0,0);

  if(G.handCount[G.whoseTurn]!=H.handCount[H.whoseTurn]+2){ //tests to see if Smithy has the player draw 3 more cards then discard one or not. If not, fails the test
    test_Result=0;
  }


if(test_Result==0){
    printf("FAILED!\n");
}else{
    printf("PASSED!\n");
}


}

#include "assert.h"

void my_assert(int value, char *msg){
    if (value){
        printf("TEST PASSED - | %s |\n", msg);
    }else{
        printf("TEST FAILED - | %s |\n", msg);
    }
}
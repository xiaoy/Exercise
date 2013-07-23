#include <stdio.h>
#include <time.h>
#include "Cat.h"
int main() {
    // start bron a cat
    struct Cat* cat = CreateCat("kate");
    if(cat == 0) {
        printf("the cat is null\n");
        return 0;
    }
    // cat start digest food
    time_t tStart = time(0);
    while(cat->nFoodCount > 0) {
        time_t tNow = time(0);
        if((tNow - tStart) > 5) {
            cat->nFoodCount -= 10;
            tStart = tNow;
        }else{
            continue;
        }

        unsigned int feedFood = 0;
        printf("give %s some food:", cat->pName);
        scanf("%d", &feedFood);
        if(feedFood > 0) {
            cat->nFoodCount += feedFood;
            if(cat->nFoodCount > MAX_FOOD_COUNT) {
                cat->nFoodCount = MAX_FOOD_COUNT;
            }
        }
        printf("\nyour pet colores is:%d\n", cat->nFoodCount);
    }
    printf("your pet is die....\n");
    DieCat(cat);
    // get the food you feed

    // continue digest the food

    return 0;
}

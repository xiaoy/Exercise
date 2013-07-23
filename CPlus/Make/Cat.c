#include "Cat.h"
#include <memory.h>
#include <stdlib.h>
#include <string.h>
struct Cat* CreateCat(char* name) {
    if(name == 0) {
        return 0;
    }
    struct Cat* cat = malloc(sizeof(struct Cat));
    cat->pName = malloc(sizeof(char) * 100);
    cat->nFoodCount = MAX_FOOD_COUNT/2;
    strncpy(cat->pName, name, strlen(name));
    return cat;
}

void DieCat(struct Cat* cat) {
    free(cat);
}


#include <ctime>
#include <iostream>
using namespace std;
static int now_time = time(NULL);

int RandomRange(int min, int max) {
    srand(now_time);
    now_time = rand();
    return (min + (rand())%(max-min));
}

float RandomRange(float min, float max) {
    srand(now_time);
    now_time = rand();
    float gap = max - min;
    return (min + (rand()/(float)RAND_MAX) * gap);
}

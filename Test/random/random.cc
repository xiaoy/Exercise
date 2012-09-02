#include <iostream>
#include <cmath>
#include <ctime>
#include <map>
#include <sys/time.h>
using namespace std;
#define TEST_COUNT 10000000
static int s_rand = time(NULL);
float RandomFloat()
{   
    srand(s_rand);
    int i =  rand();
    s_rand = i;
    return (float)(i%100)/100;
}

int main() 
{
    float per_array[] ={0.1, 0.12, 0.2, 0.26, 0.32};

    timeval tim;
    gettimeofday(&tim, NULL);
    
    cout<<"start time:"<<tim.tv_sec<<"the micro sec is:"<<tim.tv_usec<<"\n";
    map<float, int> per_map;     
    for(int i = 0; i < TEST_COUNT; ++i) {
        float frand = RandomFloat();
        float min = 0;
        float max = 1.0f;
        for(int i =0; i < 5; ++i){
            min = max - per_array[i];
            if(frand >= min){
                per_map[per_array[i]]++; 
                break;
            }
            max = min;
        }
    }
    
    gettimeofday(&tim, NULL);
    cout<<"end time:"<<tim.tv_sec<<"the micro sec is:"<<tim.tv_usec<<"\n";
    map<float, int>::iterator iter = per_map.begin(); 
    for(;iter != per_map.end(); ++iter) {
        float per_count = (float)iter->second;
        cout<<"the per:"<<iter->first<<"\tresult per:"<<per_count/TEST_COUNT<<endl;
    }
    return 0;
}


#include <boost/random/mersenne_twister.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <iostream>
#include <map>
#include <ctime>
#include <sys/time.h>
#define TEST_COUNT 10000000
int main() {
    boost::mt19937 gen;
    double probabilities[] ={0.1, 0.12, 0.2, 0.26, 0.32};
    boost::random::discrete_distribution<> dist(probabilities);

    struct timeval tim;
    gettimeofday(&tim, NULL);
    std::cout<<"start time:"<<tim.tv_sec<<"the micro sec is:"<<tim.tv_usec<<"\n";
    std::map<float, int> statis_map;
    for(int i = 0; i < TEST_COUNT; ++i) {
        statis_map[probabilities[dist(gen)]]++;
    }
    gettimeofday(&tim, NULL);
    std::cout<<"end time:"<<tim.tv_sec<<"the micro sec is:"<<tim.tv_usec<<"\n";

    for(std::map<float, int>::iterator iter = statis_map.begin(); iter != statis_map.end(); ++iter) {
        std::cout<<"the per:"<<iter->first<<"\tresult per:"<<(float)iter->second/TEST_COUNT<<"\n";
    }
    return 0;
}

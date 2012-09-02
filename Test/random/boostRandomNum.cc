#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

int main() {
    boost::random::mt19937 rng;
    boost::random::uniform_int_distribution<int> index_dis(0, 10);
    std::cout<<"the num is:";
    for(int i =0; i < 10; ++i) {
        std::cout<<index_dis(rng)<<"\t";
    }
    std::cout<<"\n";
    return 0;
}

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

int main() {
    std::string chars(
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "1234567890"
        "!@#$%^&*()"
        "`~-_=+[{]{\\|;:'\",<.>/? ");
    boost::random::mt19937 rng;
    boost::random::uniform_int_distribution<int> index_dist(0, chars.size() - 1);
    std::cout<<"You pwd is:\t";
    for(int i = 0; i < 8; ++i) {
        std::cout << chars[index_dist(rng)];
    }
    std::cout << std::endl;
}

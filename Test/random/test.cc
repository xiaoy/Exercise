#include <iostream>
#include <ctime>

static int seed = time(NULL);
int GetRandNum(int min, int max) {
    srand(seed);
    return (min + rand() %(max - min +1));
}
int main() {
 //   std::cout<<"the num is:";
 //   for(int i = 0; i < 10; ++i) {
 //       std::cout<<GetRandNum(1, 10)<<"\t";
 //   }
 //   std::cout<<"\n";
    std::string name;
    std::cout<<"your name is:";
    std::cin>>name;
    std::cout<<name<<", welcome to beijing\n";
}

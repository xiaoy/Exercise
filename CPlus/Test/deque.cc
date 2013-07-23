#include <iostream>
#include <deque>
int main() {
    std::deque<int> students;
    for(int i = 0; i < 10; ++i)
        students.push_back(i);
    std::deque<int>::iterator iter = students.begin();
    for(int i= 1; i < 5; ++i)
       iter = students.insert(iter, i * 5);
    for(;iter != students.end(); ++iter) {
        std::cout<<*iter<<std::endl;
    }
}

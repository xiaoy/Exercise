#include <iostream>
using namespace std;

int main() {
    int num = 2;
    int other = 3;

    // assignment
    const int* ptr1 = &num;
    int const* ptr2 = &num;
    int *const ptr3 = &num;
    const int* const ptr4 = &num;

    // change value
    ptr1 = &other;
    ptr2 = &other;
    // ptr3 = &other;
    // ptr4 = &other;

    // *ptr1 = other;
    // *ptr2 = other;
    *ptr3 = other;
    // *ptr4 = other;
    return 0;
}

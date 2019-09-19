#include <iostream>
#include "circular_buffer.h"

int main() {
    CircularBuffer<int> dafaq(5);
    for (size_t i = 0; i < 6; ++i) {
        dafaq.push_back(i + 1);
    }
    dafaq.pop_back();
    dafaq.pop_back();
    dafaq.pop_front();
    std::cout << "front ==" << dafaq.get_front() << std::endl;
    std::cout << "back ==" << dafaq.get_back() << std::endl;
    dafaq.print_private();
    dafaq.print_buffer();
    return 0;
}
#include <iostream>
#include "circular_buffer.h"

int main() {
    CircularBuffer<int> dafaq(5);
    for (size_t i = 0; i < 5; ++i) {
        dafaq.push_front(i + 1);
    }
    dafaq.insert(3,42);
    std::cout << "front ==" << dafaq.get_front() << std::endl;
    std::cout << "back ==" << dafaq.get_back() << std::endl;
    dafaq.print_private();
    dafaq.print_buffer();
    return 0;
}
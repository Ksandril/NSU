#include <iostream>
#include "circular_buffer.h"
///#define mainhand 42
#ifdef mainhand
int main() {
    CircularBuffer<int> dafaq(5);
    for (int i = 0; i < 5; ++i) {
        dafaq.push_back(i + 1);
    }
    dafaq.resize(3,12);
    dafaq.resize(6,12);

    std::cout << "front ==" << dafaq.get_front() << std::endl;
    std::cout << "back ==" << dafaq.get_back() << std::endl;
    std::cout << "сapacity ==" << dafaq.get_capacity() << std::endl;
    dafaq.print_private();
    dafaq.print_buffer();

    return 0;
}
#endif

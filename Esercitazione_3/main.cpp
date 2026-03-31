#include <iostream>
#include "rational.hpp"

int main() {
    rational<int> r(3, 6);
    std::cout << r << "\n"; 

    rational<int> a(1, 2);
    rational<int> b(1, 0); // Inf
    std::cout << (a + b) << "\n"; 

    return 0;
}
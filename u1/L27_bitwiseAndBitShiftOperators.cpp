#include <iostream>

int main()
{

    // operations must be bracketed

    // 1. AND bitwise operator
    char a{0b00000111};
    char b{-0b01111101};
    std::cout << "a & b = " << (a & b) << std::endl; // 00000011 <- 3

    // 2. OR bitwise operator
    std::cout << "a | b = " << (a | b) << std::endl; // 10000111 <- -121

    // 3. EXCLUSIVE-OR bitwise operator
    std::cout << "a ^ b = " << (a ^ b) << std::endl; // 10000100 <- -124

    // Automatic bitwise assignment operators
    a %= b;
    a |= b;
    a ^= b;

    // ------ bit-shift operators

    // 1. left-shift, <<
    char c{0b00111011};
    std::cout << "c << 2 = " << (c << 2) << std::endl; // 11101100 = 236

    // 2. right-shift, >>
    std::cout << "c >> 2 = " << (c >> 2) << std::endl; // 00001110 = 14

    return 0;
}
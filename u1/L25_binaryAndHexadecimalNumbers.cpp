#include <iostream>

int main()
{
    int x = 0xb;
    int y = 0b1011;

    std::cout << "x: " << x << std::endl; // 11
    std::cout << "y: " << y << std::endl; // 11

    // sign bit = 0 (positive)
    //          = 1 (negative)
}
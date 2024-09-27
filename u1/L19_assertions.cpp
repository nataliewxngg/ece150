#include <iostream>
#include <cassert>

int main()
{
    int n;

    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    assert(n >= 0); // program terminate here if number entered is negative
    std::cout << "Yay!";

    return 0;
}
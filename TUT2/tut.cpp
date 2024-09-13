#include <iostream>

int main()
{
    int a{};
    double b{};
    std::cout << "enter 2 numbers: ";
    std::cin >> a >> b;
    std::cout << "a: " << a << ", " << b;
    std::cout << std::endl;

    return 0;
}
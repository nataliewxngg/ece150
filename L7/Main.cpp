#include <iostream>

int main();

int main()
{
    std::cout << 3 + 5 << std::endl;  // addition
    std::cout << 7 - 6 << std::endl;  // subtraction
    std::cout << 8 * 9 << std::endl;  // multiplication
    std::cout << 1 / 2 << std::endl;  // division
    std::cout << 10 % 3 << std::endl; // modulus

    std::cout << 5 + 3 * 2 << std::endl; // BEDMAS

    // Initiating variables with arithmetic expressions
    int x1{5 + 8}; // x = 13
    std::cout << x1 << std::endl;
    double meow{3.14000000};
    std::cout << meow << std::endl;

    // *************
    std::cout << 3.5 / 2 << std::endl; // like java, this results in a floating point #
    // *************

    // Output testing
    std::cout << (10.0 + 3.0 / (9 / 2)) << std::endl; // 10.75
    std::cout << (10.0 + 3.0 / 9 * 2) << std::endl;   // 10.6667
    std::cout << (10.0 + 3 / (9 / 2.0)) << std::endl; // 10.6667

    // Unary Operators
    std::cout << -(1 + 2 - 5) << std::endl;
    std::cout << +(1 + 2 - 5) << std::endl;

    int x{2};
    int y{3};

    if (x >= y)
    {
        std::cout << "The max # is x: " << x << std::endl;
    }
    else
        std::cout << "The max # is y: " << y << std::endl;

    return 0;
}
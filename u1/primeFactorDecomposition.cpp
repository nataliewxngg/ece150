#include <iostream>
#include <cassert>

int main()
{
    int in;
    std::cout << "Enter a number: ";
    std::cin >> in;
    assert(in > 1);

    while (in > 1)
    {
        int divisor{2};
        int exponent{0};

        while (in % divisor != 0)
        {
            divisor++;
        }
        while (in % divisor == 0)
        {
            exponent++;
            in /= divisor;
        }

        std::cout << divisor << "^" << exponent;
        if (in > 1)
        {
            std::cout << " * ";
        }
    }
    std::cout << std::endl;

    return 0;
}
#include <iostream>
#include <cassert>

int main()
{
    int n;

    std::cout << "Enter a size: ";
    std::cin >> n;
    assert(n % 2 != 0 && n >= 3);

    for (int i{0}; i < n; ++i)
    {
        std::cout << "$";
    }
    std::cout << std::endl;

    for (int i{0}; i < n - 1; ++i)
    {
        for (int j{0}; j < (n / 2); ++j)
        {
            std::cout << " ";
        }
        std::cout << "$" << std::endl;
    }

    return 0;
}
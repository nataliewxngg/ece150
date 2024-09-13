#include <iostream>

int main();

int main()
{
    // Print Hello 10 times
    for (int i{0}; i < 10; ++i)
    {
        std::cout << "Hello" << std::endl;
    }

    // Determine factorial 5 (5!)
    int factorial{0};
    for (int i{1}; i <= 5; ++i)
    {
        factorial += i;
    }
    std::cout << factorial << std::endl;

    // Is n prime?
    int n{15};
    if (n <= 1)
        std::cout << "No" << std ::endl;
    else if (n % 2 == 0)
        std::cout << "Yes" << std::endl;
    else
    {
        for (int i{3}; i < n; i += 2)
        {
            if (n % i == 0)
            {
                i = n;
                std::cout << "Yes" << std::endl;
            }
            else if (i == n - 1)
                std::cout << "No" << std::endl;
        }
    }

    // Creating an ASCII chart
    for (int m{0}; m < 5; ++m)
    {
        std::cout << "**********" << std::endl;
    }

    // Creating a staircase
    for (int m{1}; m <= 5; ++m)
    {
        for (int n{1}; n <= m; ++n)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}
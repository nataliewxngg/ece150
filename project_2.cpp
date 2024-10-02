#include <iostream>
#include <cassert>
#include <climits>

void pattern(unsigned int n)
{
    if (n == 0)
        std::cout << "*" << std::endl;
    else
    {
        std::string space{""};
        int numOfAsterisks = n * 2 + 1;
        bool dec = true;

        for (int i{0}; i < n * 2 + 1; ++i)
        {
            // output
            std::cout << space;
            for (int k{0}; k < numOfAsterisks; ++k)
            {
                std::cout << "*";
            }

            // setup for next
            if (numOfAsterisks == 1)
                dec = false;
            if (dec)
            {
                space += " ";
                numOfAsterisks -= 2;
            }
            else
            {
                space = space.substr(0, space.size() - 1);
                numOfAsterisks += 2;
            }

            std::cout << std::endl;
        }
    }
}

unsigned int log10(unsigned int n)
{
    assert(n != 0);

    int m{0};
    int pow{1};

    while (pow <= n)
    {
        pow *= 10;
        ++m;
    }
    --m;

    return m;
}

unsigned int count(unsigned int n, unsigned int bit)
{
    assert(bit == 0 || bit == 1);
    unsigned int i{0};

    while (n)
    {
        if (bit == 1)
            i += n & 1;
        else
            i += !(n & 1);

        n >>= 1;
    }

    return i;
}

unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1)
{
}

int main()
{
    std::cout << log10(1200) << std::endl; // WORKS
    pattern(3);                            // WORKS
    std::cout << count(4, 0) << std::endl; // WORKS

    return 0;
}
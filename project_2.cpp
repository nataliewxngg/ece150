#include <iostream>
#include <cassert>

void pattern(unsigned int n)
{
    if (n == 0)
        std::cout << "*" << std::endl;
    else
    {
        std::string space{""};
        int num_of_asterisks = n * 2 + 1;
        bool dec = true;

        for (unsigned int i{0}; i < n * 2 + 1; ++i)
        {
            // output
            std::cout << space;
            for (int k{0}; k < num_of_asterisks; ++k)
            {
                std::cout << "*";
            }

            // setup for next
            if (num_of_asterisks == 1)
                dec = false;
            if (dec)
            {
                space += " ";
                num_of_asterisks -= 2;
            }
            else
            {
                space = space.substr(0, space.size() - 1);
                num_of_asterisks += 2;
            }

            std::cout << std::endl;
        }
    }
}

unsigned int log10(unsigned int n)
{
    assert(n != 0);

    int m{0};
    unsigned int pow{1};

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
    assert((b0 >= 0 && b0 <= 3) && (b1 >= 0 && b1 <= 3));

    if (b0 == b1)
        return n;

    unsigned int out{0};

    // do stuff here
    unsigned int byte0{(n << (8 * 3)) >> 8 * 3};
    unsigned int byte1{((n << (8 * 2)) >> 8 * 3) << 8};
    unsigned int byte2{((n << (8)) >> 8 * 3) << 8 * 2};
    unsigned int byte3{(n >> 8 * 3) << 8 * 3};

    for (unsigned int i{0}; i < 3; ++i)
    {
        if (b0 == i)
        {
            // make a new int with the replacement byte repositioned to the appropriate space
            // |= on to the output
            unsigned int replacement_byte{};
            unsigned int replacement_byte1{};

            if (b1 == 0)
                replacement_byte = byte0;
            else if (b1 == 1)
                replacement_byte = byte1;
            else if (b1 == 2)
                replacement_byte = byte2;
            else
                replacement_byte = byte3;

            if (i == 0)
                replacement_byte1 = byte0;
            else if (i == 1)
                replacement_byte1 = byte1;
            else if (i == 2)
                replacement_byte1 = byte2;
            else if (i == 3)
                replacement_byte1 = byte3;

            if (b1 < b0)
            {
                replacement_byte1 >>= 8 * (b0 - b1);
                replacement_byte <<= 8 * (b0 - b1);
            }
            else
            {
                replacement_byte1 <<= 8 * (b1 - b0);
                replacement_byte >>= 8 * (b1 - b0);
            }

            out |= replacement_byte;
            out |= replacement_byte1;
        }
        else if (b1 != i)
        {
            if (i == 0)
                out |= byte0;
            else if (i == 1)
                out |= byte1;
            else if (i == 2)
                out |= byte2;
            else
                out |= byte3;
        }
    }

    return out;
}

int main()
{
    std::cout << count(32, 0); // 100000

    return 0;
}
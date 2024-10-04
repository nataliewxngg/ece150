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

    unsigned int m{0};
    while (n >= 10)
    {
        n /= 10;
        ++m;
    }

    return m;
}

unsigned int count(unsigned int n, unsigned int bit)
{
    assert(bit == 0 || bit == 1);
    unsigned int out{0};

    while (n)
    {
        out += n & 1;
        n >>= 1;
    }

    if (bit)
        return out;
    else
        return 32 - out;
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

    for (unsigned int i{0}; i < 4; ++i)
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

void test()
{
    // pattern

    std::cout << "\n------------------ pattern() ------------------" << std::endl;

    std::cout
        << "\nTest case #1:\n";
    std::cout << "Expected: \n*\n";
    std::cout << "Your output: \n";
    pattern(0);

    std::cout << "\nTest case #2: \n";
    std::cout << "Expected: \n*****\n *** \n  *  \n *** \n*****\n";
    std::cout << "Your output: \n";
    pattern(2);

    std::cout << "\nTest case #3: \n";
    std::cout << "Expected: \n***********************\n ********************* \n  *******************  \n   *****************    \n    ***************     \n     *************      \n      ***********       \n       *********        \n        *******         \n         *****          \n          ***           \n           *      \n          ***         \n         *****        \n        *******       \n       *********      \n      ***********     \n     *************     \n    ***************    \n   *****************   \n  *******************  \n ********************* \n***********************";
    std::cout << "\nYour output: \n";
    pattern(11);

    // log19
    std::cout << "\n------------------ log10() ------------------" << std::endl;
    std::cout << "\nTest case #4:" << std::endl;
    std::cout << "Expected: 2";
    std::cout << "\nYour output: " << log10(280) << std::endl;

    std::cout << "\nTest case #5:" << std::endl;
    std::cout << "Expected: 9";
    std::cout << "\nYour output: " << log10(2398479827) << std::endl;

    std::cout << "\nTest case #6:" << std::endl;
    std::cout << "Expected: 0";
    std::cout << "\nYour output: " << log10(1) << std::endl;

    // count
    std::cout << "\n------------------ count() ------------------" << std::endl;

    std::cout << "\nTest case #7:" << std::endl;
    std::cout << "Expected: 31";
    std::cout << "\nYour output: " << count(32, 0) << std::endl;

    std::cout << "\nTest case #8:" << std::endl;
    std::cout << "Expected: 32";
    std::cout << "\nYour output: " << count(0, 0) << std::endl;

    std::cout << "\nTest case #9:" << std::endl;
    std::cout << "Expected: 16";
    std::cout << "\nYour output: " << count(387298673, 1) << std::endl;

    std::cout << "\nTest case #10:" << std::endl;
    std::cout << "Expected: 26";
    std::cout << "\nYour output: " << count(3972, 0) << std::endl;

    std::cout << "\nTest case #11:" << std::endl;
    std::cout << "Expected: 2";
    std::cout << "\nYour output: " << count(5, 1) << std::endl;

    // swap_bytes

    std::cout << "\n------------------ count() ------------------" << std::endl;

    std::cout << "\nTest case #12:" << std::endl;
    std::cout << "Expected: " << 0b10110101100100000111111101011011;
    std::cout << "\nYour output: " << swap_bytes(0b10110101010110110111111110010000, 0, 2) << std::endl;

    std::cout << "\nTest case #13:" << std::endl;
    std::cout << "Expected: " << 0b00000100000000010000001000001000;
    std::cout << "\nYour output: " << swap_bytes(0b00000100000010000000001000000001, 0, 2) << std::endl;

    std::cout << "\nTest case #14:" << std::endl;
    std::cout << "Expected: " << 0b01111111010110111011010110010000;
    std::cout << "\nYour output: " << swap_bytes(0b10110101010110110111111110010000, 3, 1) << std::endl;

    std::cout << std::endl;
}

int main()
{
    test();
    return 0;
}
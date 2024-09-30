#include <iostream>

int main()
{
    // Array Declarations
    // capacity MUST be included, but initial values are optional
    std::string totatoYaklt[5]{"Natalie", "Abby"}; // array of 5 strings

    for (int i{0}; i < 5; ++i)
    {
        std::cout << totatoYaklt[i] << std::endl;
    }

    totatoYaklt[2] = "Robert";
    totatoYaklt[3] = "Eric";
    totatoYaklt[4] = "Raymond";

    for (int i{0}; i < 5; ++i)
    {
        std::cout << totatoYaklt[i] << std::endl; // should all be null
    }

    // Exceeding array bounds
    totatoYaklt[-1] = "WHAT";
    totatoYaklt[5] = "HUH";
    std::cout << totatoYaklt[-1] << std::endl;
    std::cout << totatoYaklt[5] << std::endl;

    return 0;
}
#include <iostream>

int main();
int main()
{
    int *p_int{};
    p_int = new int{2};
    std::cout << p_int << std::endl;

    // or

    int *p_int1{new int{2}};

    // Unallocating memory to the program
    delete p_int;
    p_int = nullptr; // forget this address

    return 0;
}
#include <iostream>

int main();
int main()
{
    // Pointers
    // Df: Variables that store an address (naming convention: "p_" prefix)

    int a{1};
    int arr_a[10];
    int *p_a{&a}; // Stores address of int a
    // <- & operator is used to get the addresses of local variables/parameters

    int *p_arr_a{arr_a}; // Stores address of int array arr_a

    std::cout << a << std::endl;
    std::cout << p_a << std::endl; // Address of int a

    // These two are the same
    std::cout << arr_a << std::endl;
    std::cout << arr_a << std::endl;

    // Accessing and modifying the variable stored in a pointer:
    int n{2};
    int *p_n{&n};

    *p_n = 3;
    std::cout << n << std::endl;    // 3
    std::cout << *p_n << std::endl; // 3

    // std::size_t <- unsigned # that can store the maximum index for a particular processor (a universal solution to the varying types of indexes to arrays)
    std::size_t cap{20};
    int arr_b[cap];

    return 0;
}
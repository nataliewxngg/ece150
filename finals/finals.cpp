#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

#define NDEBUG
#include <cassert>

// Declarations
int main();
void print_array(int arr[], std::size_t capacity);
void clear_array(int arr[], std::size_t capacity);
void throw_exception();

// print_array Definition
void print_array(int arr[], std::size_t capacity)
{
    for (std::size_t i{0}; i < capacity; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

// clear_array Definition
void clear_array(int arr[], std::size_t capacity)
{
    for (std::size_t i{0}; i < capacity; ++i)
    {
        arr[i] = 0;
    }
}

// throw_exception Definition
void throw_exception()
{
    throw std::domain_error{"no"};
}

// Main Definition
int main()
{
    // Unit 1 ----------------------------

    // Casting
    std::string sa{std::to_string(3)};
    std::cout << sa << std::endl; // 3

    int n{static_cast<int>(3.7)};
    std::cout << n << std::endl; // 3

    // Literal data
    int a{9};
    char c{'n'};
    std::string s{"nat"};
    double f{3.14};
    bool b{true};
    bool b1{1};

    // C-style strings
    char str1[3]{'h', 'i'};
    char str2[3]{'y', 'o', ' '};
    std::cout << str2 << std::endl; // yo hi

    // Binary and Hexadecimal
    short m{0b01101100};
    short m1{0x6C};
    std::cout << m << std::endl;  // 108
    std::cout << m1 << std::endl; // 108

    // Arrays
    int arr1[2]{1, 2};
    int arr2[3]{3, 4, 5};
    // arr1 = arr2; // NOT ALLOWED
    print_array(arr1, 2);
    print_array(arr2, 3);

    // Arrays are passed by reference...
    clear_array(arr2, 3);
    print_array(arr2, 3);

    // Aliases
    const unsigned int mickey{19};
    const unsigned int &minnie{mickey};

    // Unit 2 ----------------------------

    int oof{2};
    int *p_oof{&oof};

    int arr[3]{2, 4, 6};
    int *p_arr{arr};

    *p_oof = 3;
    std::cout << oof << " = " << *p_oof << std::endl; // 3 = 3
    oof = 5;
    std::cout << oof << " = " << *p_oof << std::endl; // 5 = 5

    // wild pointers - not initialized properly
    // dangling pointers - point at deallocated memory
    // memory leak - loss of address to memory allocated to program

    int *p_num{new int{32}};
    delete p_num;
    p_num = nullptr;

    int *a_nums{new int[3]{2, 3, 4}}; // (nothrow) goes AFTER the new operator
    delete[] a_nums;
    a_nums = nullptr;

    // Unit 4 ----------------------------

    try
    {
        throw_exception();
    }
    catch (std::domain_error &e)
    {
        std::cout << e.what() << std::endl; // no
    }

    return 0;
}

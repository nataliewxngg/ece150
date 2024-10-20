#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>
#include <iostream> // std::to_string()

int main();

int area(const int m, const int n)
{
    return m * n;
}

void change(int arr[], int a)
{
    arr[a] = 0;
}

int main()
{
    int n{9};
    double p{3.14};
    char c{c};
    const std::string name{"Nat"};
    bool b{1};

    const signed int i1{2};
    const unsigned int &i2{i1};

    int iarr[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << area(2, 12) << std::endl;

    change(iarr, 3);
    for (int i{0}; i < 10; ++i)
        std::cout << iarr[i] << std::endl;

    std::cout << (n >> 1) << std::endl; // 0b100
    std::cout << n << std::endl;        // 0b1001
}
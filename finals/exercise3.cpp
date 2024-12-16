#include <iostream>

// 3.07
unsigned int factorial(unsigned int const n);
unsigned int binomial(unsigned int const n, unsigned int const k);
unsigned int fibonacci(unsigned int const n);
double power(double const x, int const n);

// 3.08 - skip - won't be tested
void selection_sort(double array[], std::size_t capacity);
void insertion_sort(double array[], std::size_t capacity);
void print_binary(int const n);
std::size_t binary_search(double array[], std::size_t capacity, double value);

unsigned int factorial(unsigned int const n)
{
    if (n <= 1)
        return 1;
    return factorial(n * (n - 1));
}

unsigned int binomial(unsigned int const n, unsigned int const k)
{
    if (k > n)
        return 0;
    else if (k == 0 || k == n)
        return 1;
    return binomial(n - 1, k) + binomial(n - 1, k - 1);
}

unsigned int fibonacci(unsigned int const n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

double power(double const x, int const n)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return 1 / power(x, -n);
    return x * power(x, n - 1);
}
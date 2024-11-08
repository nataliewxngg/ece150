#include <iostream>

// factorial
unsigned int factorial(unsigned int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// binomial coefficients
unsigned int binomial(unsigned int n, unsigned int k)
{
    if (k > n)
        return 0;
    else if (k == 0 || k == n)
        return 1;
    else
    {
        return binomial(n - 1, k) + binomial(n - 1, k - 1);
    }
}

// fibonacci numbers
unsigned int fibonacci(unsigned int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// integer exponents
double power(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n > 0)
        return x * power(x, n - 1);
    else
        return 1 / power(x, -n); // 2^-1 = 1/2^1
}

int main();
int main()
{
    std::cout << factorial(5) << std::endl;

    return 0;
}
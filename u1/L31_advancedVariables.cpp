#include <iostream>

void reset_passByValue(int n)
{
    n = 0;
}
void reset_passByRef(int &n)
{
    n = 0;
}

void minAndMax(int a, int b, int c, int &max, int &min)
{
    if (a < b)
    {
        min = a;
        max = b;
    }
    else
    {
        min = b;
        max = a;
    }
    if (c < min)
    {
        min = c;
    }
    else if (c > max)
    {
        max = c;
    }
}

int main()
{
    // Alias (reference local variables)
    int m{1};
    int &n{m};

    std::cout << "m: " << m << std::endl;
    std::cout << "n: " << n << std::endl;

    n = 21; // changes m too
    std::cout << "m: " << m << std::endl;
    std::cout << "n: " << n << std::endl;

    m = 7; // changes n too
    std::cout << "m: " << m << std::endl;
    std::cout << "n: " << n << std::endl;

    // --------------------------------

    // Pass by reference (in arguments!)
    int k{85};
    reset_passByValue(k);
    std::cout << "k: " << k << std::endl;
    reset_passByRef(k);
    std::cout << "k: " << k << std::endl;

    // eg.
    int max;
    int min;
    minAndMax(5, 9, 8, max, min);

    std::cout << "min: " << min << std::endl;
    std::cout << "max: " << max << std::endl;

    return 0;
}
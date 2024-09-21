#include <iostream>
#include <string>

int get_value_no_less_than(std::string text, int lower_bound)
{
    int num;
    do
    {
        std::cout << text;
        std::cin >> num;
    } while (num < lower_bound);
}

int binomial(int n, int k)
{
    int nf = 1;
    int kf = 1;
    int n_kf = 1;

    if (n < 0 || k < 0 || k > n)
        return 0;
    else
    {
        for (int i{1}; i <= n; ++i)
            n *= i;
        for (int i{1}; i <= k; ++i)
            k *= i;
        for (int i{1}; i <= (n - k); ++i)
            n_kf *= i;
    }
    return nf / (kf * (n_kf));
}

int main();

int main()
{
    get_value_no_less_than("dkjfalj", 3);
    return 0;
}
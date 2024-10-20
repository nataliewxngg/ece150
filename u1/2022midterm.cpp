#include <iostream>
int main();

unsigned int ilog2(unsigned int n)
{
    // assume we return 0 if n=0 (since no possible value m will give 2^m=0)
    if (n == 0 || n == 1)
        return 0;

    int num{1};
    int m{0};
    while (num <= n)
    {
        ++m;
        num *= 2;
    }
    return m - 1;
}

void even_sets_odd(int &num)
{
    int mask{1};

    while ((mask << 1) != 0)
    {
        if ((mask & num) != 0)
        { // bit is a 1
            mask <<= 1;
            if ((mask & num) == 0)
                num |= mask;
            else
            {
                mask = ~mask;
                num &= mask;
                mask = ~mask;
            }
        }
        else
        {
            mask <<= 1;
            num |= mask;
        }
        mask <<= 1;
    }
}

int is_sub_array(int arr1[], int cap1, int arr2[], int cap2)
{
    for (int i{0}; i < cap2; ++i)
    {
        if (arr2[i] == arr1[0])
        {
            for (int j{1}; j < cap1; ++j)
            {
                if (arr1[j] != arr2[i + j])
                {
                    break;
                }
                if (j == cap1 - 1)
                    return i;
            }
        }
    }
    return cap2;
}

void remove_entries(int arr[], int cap, int start, int count)
{
    for (int i{start + count}; i < cap; ++i)
    {
        arr[i - count] = arr[i];
        arr[i] = 0;
    }
}

int main()
{
    // int n{};
    // std::cout << "Enter an integer: ";
    // std::cin >> n;
    // // Fill in your solution here:
    // int div{};
    // for (int i{1}; i <= n; ++i)
    // {
    //     if (n % i == 0)
    //     {
    //         ++div;
    //     }
    // }
    // std::cout << div << std::endl;

    // std::cout << ilog2(7) << std::endl;

    // int form1;
    // for (int i{3}; i <= 13; ++i)
    // {
    //     form1 = 0;

    //     for (int j{1}; j <= i; ++j)
    //     {
    //         form1 += j * (j + 1) * (j + 2);
    //     }
    //     std::cout << "for n=" << i << ": " << form1 << std::endl;
    //     std::cout << "for n=" << i << ": " << 0.25 * i * (i + 1) * (i + 2) * (i + 3) << std::endl;
    // }

    // int m{0b0001};
    // std::cout << (m | 127) << std::endl;

    // int hi{0b0001};
    // even_sets_odd(hi);
    // std::cout << hi << std::endl;

    // int n;
    // std::cout << "Enter n: ";
    // std::cin >> n;
    // int num_of_num{1};
    // for (int row{0}; row <= n; ++row)
    // {
    //     for (int j{0}; j < (n - row); ++j)
    //     {
    //         std::cout << " ";
    //     }
    //     for (int k{0}; k < num_of_num; ++k)
    //     {
    //         std::cout << std::to_string(n - row);
    //     }
    //     num_of_num += 2;
    //     std::cout << std::endl;
    // }
    // return 0;

    int arr1[5]{2, 5, 4, 2, 1};
    int arr2[10]{0, 2, 4, 3, 2, 5, 4, 2, 1, 3};
    std::cout << is_sub_array(arr1, 5, arr2, 10) << std::endl;

    int arr3[5]{1, 2, 6, 3, 2};
    remove_entries(arr3, 5, 0, 2);
    for (int i{0}; i < 5; ++i)
    {
        std::cout << arr3[i] << std::endl;
    }
}
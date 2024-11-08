#include <iostream>

bool is_sorted(int const arr[], std::size_t cap)
{
    for (std::size_t i{1}; i < cap; ++i)
    {
        if (arr[i] < arr[i - 1])
            return 0;
    }

    return 1;
}
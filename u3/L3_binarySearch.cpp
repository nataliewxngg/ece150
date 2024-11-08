#include <iostream>
#include <cassert>
#include "L2_sortedArrays.cpp"

// Binary search will have to inspect no more than log(n)+1 entries
// whereas linear search may have to inspect up to n entries

std::size_t binary_search(int const arr[], std::size_t cap, int val)
{
    assert(is_sorted(arr, cap));

    std::size_t low{0};
    std::size_t high{cap - 1};

    while (low <= high && high < cap)
    {
        std::size_t avg{(low + high) / 2};

        if (arr[avg] == val)
            return avg;
        else if (val < arr[avg])
            high = avg - 1;
        else
            low = avg + 1;
    }
    return cap; // Return cap if val is not found
}
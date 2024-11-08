#include <iostream>
#include "L2_sortedArrays.cpp"

void selection_sort(int arr[], std::size_t cap)
{
    if (!is_sorted(arr, cap))
    {
        int largest_index;
        for (std::size_t i{0}; i < cap; ++i)
        {
            largest_index = 0;
            for (std::size_t j{0}; j < cap - i; ++j)
            {
                if (arr[j] > arr[largest_index])
                    largest_index = j;
            }
            int tmp{arr[cap - 1 - i]};
            arr[cap - i - 1] = arr[largest_index];
            arr[largest_index] = tmp;
        }
    }
}

int main();
int main()
{
    int arr[10]{1, 3, 7, 2, 8, 9, 0, 5, 4, 6};
    selection_sort(arr, 10);
    for (std::size_t i{0}; i < 10; ++i)
    {
        std::cout << arr[i];
        if (i != 9)
            std::cout << ", ";
    }
}
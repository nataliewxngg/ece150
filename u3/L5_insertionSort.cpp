#include <iostream>

void insertion_sort(int arr[], std::size_t cap)
{
    for (std::size_t i{1}; i < cap; ++i)
    {
        int val = arr[i];

        for (std::size_t j{i - 1}; j >= 0; --j)
        {
            if (arr[j] > val)
            {
                arr[j + 1] = arr[j];
                arr[j] = val;
            }
            if (j == 0)
                break;
        }
    }
}

int main();
int main()
{
    int arr[10]{1, 3, 7, 2, 8, 9, 0, 5, 4, 6};
    insertion_sort(arr, 10);
    for (std::size_t i{0}; i < 10; ++i)
    {
        std::cout << arr[i];
        if (i != 9)
            std::cout << ", ";
    }
}
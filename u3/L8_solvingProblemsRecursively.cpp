#include <iostream>

// Selection sort
// Continuously move the largest element to the end
int find_max_index(int const arr[], std::size_t cap)
{
    std::size_t out = 0;

    for (std::size_t i{0}; i < cap; ++i)
    {
        if (arr[i] > arr[out])
            out = i;
    }
    return out;
}

void selection_sort(int arr[], std::size_t cap)
{
    // Base case
    if (cap <= 1)
        return;
    else
    {
        int tmp{arr[find_max_index(arr, cap)]};
        arr[find_max_index(arr, cap)] = arr[cap - 1];
        arr[cap - 1] = tmp;

        return selection_sort(arr, cap - 1);
    }
}

// Insertion sort
// ...

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
    return 0;
}
#include <iostream>

// return locations of arrays = a "hack" to return arrays
// int/double/... *array is another way of passing an array into a function

// eg.
// Method to clear (and deallocate - usually not included in method) a DYNAMICALLY allocated array
// (will not work for local arrays - these cannot be deallocazted)
void deallocate(double *arr, const std::size_t cap)
{
    for (std::size_t k{0}; k < cap; ++k)
    {
        arr[k] = 0.0;
    }
    delete[] arr;
    arr = nullptr;
}

int main();
int main()
{
    std::size_t cap{100};
    double *array{new double[cap]};
    std::cout << array[15] << std::endl;

    return 0;
}
#include <iostream>

// return locations of arrays = a "hack" to return arrays

int main();
int main()
{
    std::size_t cap{100};
    double *array{new double[cap]};
    std::cout << array[15] << std::endl;

    return 0;
}
#include <iostream>

// Array as a parameter
// if the array gets modified in the function, the modification will apply to the local variable too (pass by reference)
int average(int array[], unsigned int capacity)
{
    std::cout << array << std::endl;
    return 0;
}

int main()
{
    // Inability of arrays:
    // 1. Design feature: local arrays CANNOT be assigned to (a function/for loop is needed)
    int arr1[10]{};
    int arr2[10]{};

    // arr1 = arr2;

    // 2. Const array values cannot be modified after assignment
    const int primes[10]{2, 3, 5, 7, 11, 13, 17, 19, 23, 25};
    // primes[9] = 29;

    // 3. Functions CANNOT return arrays

    // --------------------------------------------

    // PASS BY REFERENCE DEMONSTRATED:
    std::cout << "Location of arr1 from main: " << arr1 << std::endl;
    std::cout << "Location of arr1 from func: ";
    average(arr1, 2);

    // ---------------------------------------------

    int arr3[5]{}; // can store (5) * (4 bytes) = 20 bytes

    return 0;
}
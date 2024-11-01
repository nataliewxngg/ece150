// This is a testing main
// It will need to be copied into the same directory as your project_3.cpp file
#include "project_3.cpp";

// These are all the possible function calls for project 3
// your code shoud be able to compile with this as its main
int main()
{
    double *test1{geometric(1.0, 2.0, 4)};

    double arr0[2]{1, 1};
    double arr1[3]{1, 1, 1};
    double *test2{cross_correlation(arr0, 2, arr1, 3)};

    int arr2[10]{1, 2, 3, 4, 5, 6, 6, 7, 8, 8};
    std::size_t num_unique{shift_duplicates(arr2, 10)};

    deallocate(test1, true, 4);
    deallocate(test2, true, 5);

    // don't forget the default parameter
    double *test3{new double{4}};
    deallocate(test3, false);

    return 0;
}
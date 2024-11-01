#include <iostream>
#include <cassert>

// Method #1
double *geometric(double a, double ratio, std::size_t cap)
{
    double *a_arr{new double[cap]};

    for (std::size_t k{0}; k < cap; ++k)
    {
        a_arr[k] = a;
        for (double j{0}; j < k; ++j)
        {
            a_arr[k] *= ratio;
        }
    }

    return a_arr;
}

// Method #2
double *cross_correlation(
    double array0[], std::size_t cap0, double array1[], std::size_t cap1)
{
    assert((cap0 + cap1) >= 1);

    // Initiating all values with 0.0
    double *a_arr{new double[cap0 + cap1 - 1]};
    for (std::size_t k{0}; k < cap0 + cap1 - 1; ++k)
    {
        a_arr[k] = 0.0;
    }

    // Adding each result at index i+j with array0[i]*array1[j]
    for (std::size_t i{0}; i < cap0; ++i)
    {
        for (std::size_t j{0}; j < cap1; ++j)
        { // < cap1 or < i?
            a_arr[i + j] += array0[i] * array1[j];
        }
    }

    return a_arr;
}

// Method #3
std::size_t shift_duplicates(int array[], std::size_t capacity)
{
    std::size_t num_of_dupes{0};

    for (std::size_t i{0}; i < capacity - num_of_dupes; ++i)
    {
        if (i != capacity - 1) // if the left pointer is not at the end of the array
        {
            for (std::size_t j{i + 1}; j < capacity; ++j)
            {
                if (array[i] == array[j])
                {
                    int dupe = array[i];

                    // shift everything between i and j once to the left
                    for (std::size_t m{i}; m < j - 1; ++m)
                    {
                        array[m] = array[m + 1];
                    }

                    // shift everything behind j twice to the left
                    for (std::size_t n{j}; n < capacity - 1; ++n)
                    {
                        array[n - 1] = array[n + 1];
                    }

                    // add dupes to the end
                    array[capacity - 1] = array[capacity - 2] = dupe;
                    if (j < capacity - num_of_dupes) // duplicate not already identified
                        num_of_dupes += 2;
                    else
                    {
                        ++num_of_dupes;
                        break; // j=capacity;
                    }

                    if (i < capacity - num_of_dupes)
                        j = i; // start checking for new array[i] from beginning again
                    else
                        break;
                }
            }
        }
    }

    // for (std::size_t k{0}; k < capacity; ++k)
    // {
    //     std::cout << array[k] << std::endl;
    // }

    return capacity - num_of_dupes;
}

// Method #4
void deallocate(double *&ptr, bool is_array, std::size_t capacity = 0)
{
    if (is_array == 1)
    {
        // set each entry to zero
        for (std::size_t i{0}; i < capacity; ++i)
        {
            ptr[i] = 0.0;
        }
        delete ptr;
    }
    else
    {
        ptr[0] = 0.0;
    }
    ptr = nullptr;
}

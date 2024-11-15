#include <iostream>
#include <cassert>
#include "p_4_header.hpp"

// Function 2.1
std::size_t length(char const *a)
{
    std::size_t out{0};
    while (a[out] != '\0')
        ++out;
    return out;
}

// Function 2.2
int compare(char const *str1, char const *str2)
{
    std::size_t index{0};

    while (str1[index] == str2[index]) // kth character is the same
    {
        if (str1[index] == '\0') // kth character of both strings is '\0'
            return 0;

        ++index;
    }
    if (str1[index] == '\0' || str1[index] < str2[index])
        return -1;
    else
        return 1;
}

// Function 2.3
void assign(char *str1, char const *str2)
{
    // overwrite str1 with str2 (both length of 20 character excluding '\0')
    for (std::size_t i{0}; i < 21; ++i)
    {
        str1[i] = str2[i];
        if (str2[i] == '\0')
            break;
    }
}

// Function 2.4
unsigned int distance(char const *str1, char const *str2)
{
    // base cases
    if (length(str1) == 0)
        return length(str2);
    else if (length(str2) == 0)
        return length(str1);

    if (str1[0] != str2[0])
    {
        if (length(str1) > length(str2))
            return 1 + distance(str1 + 1, str2);
        else if (length(str1) < length(str2))
            return 1 + distance(str1, str2 + 1);
        else
            return 1 + distance(str1 + 1, str2 + 1);
    }
    else
        return distance(str1 + 1, str2 + 1);
}

// Function 2.5
std::size_t is_sorted(char *array[], std::size_t capacity)
{
    char *prev{array[0]};

    for (std::size_t i{1}; i < capacity; ++i)
    {
        if (compare(array[i], prev) < 0)
            return i;
        prev = array[i];
    }
    return capacity;
}

// Function 2.6
void insert(char *array[], std::size_t capacity)
{
    char *entry{array[capacity - 1]};
    std::size_t i{capacity - 1};

    for (i; compare(array[i - 1], entry) > 0; --i)
    {
        array[i] = array[i - 1];
    }
    array[i] = entry;
}

// Function 2.7
void insertion_sort(char *array[], std::size_t capacity)
{
    for (std::size_t i{2}; i <= capacity; ++i)
        insert(array, i);
}

// Function 2.8
std::size_t remove_duplicates(char *array[], std::size_t capacity)
{
    // array already sorted
    std::size_t out{0};
    for (std::size_t i{0}; i < capacity - 1; ++i)
    {
        if (compare(array[i], array[i + 1]) == 0)
        { // same characters

            // add 1
            ++out;

            // shift the characters (starting at i+2) to the left
            for (std::size_t j{i + 2}; j < capacity; ++j)
            {
                array[j - 1] = array[j];
            }

            // set i = i-1;
            --i;
        }
    }
    return out;
}

// Function 2.9
std::size_t find(char *array[], std::size_t capacity, char const *str)
{
    return 0;
}

// Function 2.11
void free_word_array(char **word_array)
{
}
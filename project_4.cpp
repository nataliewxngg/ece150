#include <iostream>
#include <cassert>

// Function 1
std::size_t length(char const *a)
{
    std::size_t out{0};
    while (a[out] != '\0')
        ++out;
    return out;
}

// Function 2
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

// Function 3
void assign(char *str1, char const *str2)
{
    // overwrite str1 with str2 (both length of 20 character excluding '\0')
    for (std::size_t i{0}; i < 20; ++i)
    {
        str1[i] = str2[i];
        std::cout << i << std::endl;
    }
}

int main();
int main()
{
    char *s1{"natalie"};
    char *s2{"dog"};
    char *s3{"cat"};
    char *s4{"i like jewelpet!!!!!"};
    char *s5{"i have an iphone 15!"};

    std::cout << length(s1) << std::endl; // 7

    std::cout << compare(s2, s3) << std::endl; // 1
    std::cout << compare(s3, s2) << std::endl; // -1
    std::cout << compare(s1, s1) << std::endl; // 0

    assign(s4, s5);
    std::cout << s4 << std::endl;
    std::cout << s5 << std::endl;

    return 0;
}
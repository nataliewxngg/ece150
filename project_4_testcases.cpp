#include <iostream>
#include <cassert>
#include "project_4.cpp"

int main();
int main()
{
    char *s1{"natalie"};
    char *s2{"dog"};
    char *s3{"cat"};
    char *s4{"moose"};
    char *s5{"zebra"};
    char test_string[21]{"cat"};

    std::cout << length(s1) << std::endl; // 7

    std::cout << compare(s2, s3) << std::endl; // 1
    std::cout << compare(s3, s2) << std::endl; // -1
    std::cout << compare(s1, s1) << std::endl; // 0

    std::cout << "The distance between " << test_string
              << " and mat is " << distance(test_string, "mat") << std::endl;

    std::cout << "cat is less than dog: " << (s3 < s2) << std::endl;
    std::cout << "dog is less than cat: " << (s2 < s3) << std::endl;

    char c[2]{'e', 'f'};
    char oo = c[0];
    c[0] = '2';
    std::cout << oo << std::endl; // still 'e'

    char *array[5]{
        s3,
        s2,
        s1,
        s5,
        s4};
    insert(array, 5);
    for (int i{0}; i < 5; ++i)
    {
        std::cout << array[i] << std::endl;
    }

    return 0;
}
#include <iostream>
#include <cassert>
#include "project_4.cpp"

int main();
int main()
{
    char *s1{"natalie"};
    char *s2{"dog"};
    char *s3{"cat"};
    char test_string[21]{"cat"};

    std::cout << length(s1) << std::endl; // 7

    std::cout << compare(s2, s3) << std::endl; // 1
    std::cout << compare(s3, s2) << std::endl; // -1
    std::cout << compare(s1, s1) << std::endl; // 0

    std::cout << "The distance between " << test_string
              << " and hat is " << distance(test_string, "hat") << std::endl;

    return 0;
}
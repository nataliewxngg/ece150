#include <iostream>

int main();

namespace natalie
{
    int birthday(int age);
    int birthday(int age)
    {
        return ++age;
    }
}

int main()
{
    std::cout << natalie::birthday(17) << std::endl;
    return 0;
}
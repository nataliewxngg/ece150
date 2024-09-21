#include <iostream>
#include <string>

int main();

int main()
{
    // Initializing with default values
    int n{};         // 0
    char ch{};       // '\0'
    double x{};      // 0.0
    bool is_valid{}; // false

    std::cout << n << std::endl;
    n = 10; // assignment
    std::cout << n << std::endl;
    std::cout << ch << std::endl;
    std::cout << x << std::endl;
    std::cout << is_valid << std::endl;

    // Initializing with custom values
    std::string name{"Natalie"};
    int age{18};

    std::cout << name << std::endl;
    std::cout << age << std::endl;

    return 0;
}
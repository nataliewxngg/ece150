#include <iostream>
#include <string> // to declare strings

// Function declarations
int main();

// Function definitions
int main()
{

    // for int -----------------------------------------
    // Local variable declaration
    int n;
    // char c;
    // double d;
    // float f;
    // bool b

    std::cout << "Enter a number: ";
    std::cin >> n; // cin - used to receive user input
    std::cout << "You entered " << n << std::endl;

    // for string --------------------------------------
    std::string name; // unique way to declare a string

    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello " << name << std::endl;

    return 0;
}
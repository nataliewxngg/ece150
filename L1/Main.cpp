#include <iostream>
// #include <math>

// Function declarations
int main();

// Function definitions
int main()
{

    // Lesson 1.01
    // Display this text to the console
    std::cout << "Hello World!"; // cout: console out
    std::cout << std::endl;      // endl: end line

    // ----------------------------------------------------

    // Lesson 1.02
    int course{150}; // a var named course
    std::cout << "Hello ECE " << course << " meow" << std::endl;

    // declares an int function gcd with 2 int parameters, m and n
    int gcd(int m, int n);

    // ----------------------------------------------------

    // Lesson 1.03
    std::cout << "The answer to the ultimate question is ";
    std::cout << 42;
    std::cout << std::endl;

    std::cout << 'a';
    std::cout << 'b';
    std::cout << 'c';
    std::cout << std::endl;

    std::cout << "\' \\"; // escape sequence

    return 0; // to end program
}
#include <iostream>

int main(); // semicolon!

int main()
{
    std::cout << "Hello ECE 150!" << std::endl;

    int course{150}; // a var named course
    std::cout << "Hello ECE " << course << " meow" << std::endl;

    return 0; // to end program
}
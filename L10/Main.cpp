#include <iostream>

int main();

int main()
{
    // Swapping variables -> Temporary local variables
    int month{5};
    int day{9};

    int tmp{month};
    month = day;
    day = tmp;
    std::cout << month << ", " << day << std::endl;

    // Automatic assignment
    int nat = 8;
    nat += 10; // nat = 18
    nat -= 8;  // nat = 10
    nat *= 5;  // nat = 50
    nat /= 25; // nat = 2
    nat %= 3;  // nat = 2
    std::cout << nat << std::endl;

    // Autoincrement/Autodecrement -> will always use ++n/--n in this class
    // logic is same as java!
    int n{752};
    std::cout << ++n << std::endl; // 753
    std::cout << n << std::endl;   // 753
    std::cout << n++ << std::endl; // 753
    std::cout << n << std::endl;   // 754

    return 0;
}
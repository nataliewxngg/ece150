#include <iostream>

int main();

int main()
{
    int x{2};
    int y{3};

    if (x >= y)
    {
        std::cout << "The max # is x: " << x << std::endl;
    }
    else
        std::cout << "The max # is y: " << y << std::endl;

    return 0;
}
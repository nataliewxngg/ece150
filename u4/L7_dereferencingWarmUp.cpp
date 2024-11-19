#include <iostream>

int main();

void foo(int *p)
{
    *p = 88; // affects parameter value (DEREFERENCING CAN MODIFY)

    int y{55};
    p = &y; // does not affect parameter value (REASSIGNMENT CANNOT MODIFY)
}

int main()
{
    int x{9};
    foo(&x);

    std::cout << x << std::endl; // 88

    return 0;
}
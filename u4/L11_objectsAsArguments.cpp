#include <iostream>

class F;
int main();
void by_reference(F &ref_param);
void by_value(F param);
void by_array(F array[], std::size_t const capacity);

class F
{
public:
    F();
    F(F const &original);
    ~F();
};

F::F()
{
    std::cout << " - Calling F()" << std::endl;
}

F::F(F const &original)
{
    std::cout << " - Calling F(F const &)" << std::endl;
}

F::~F()
{
    std::cout << " - Calling ~F()" << std::endl;
}

void by_reference(F &ref_param)
{
}
void by_value(F param)
{
}
void by_array(F array[], std::size_t const capacity)
{
    // address of the array is passed - so not constructor nor destructor is called - like the pass by reference function
}

int main()
{
    // passing a single F object into pass by reference and pass by value functions:
    F obj{};

    std::cout << "Passing by reference:" << std::endl;
    by_reference(obj);
    std::cout << "Passing by value:" << std::endl;
    by_value(obj);
    std::cout << "Returning from main: " << std::endl;

    // when calling delete on the address of an obj, that calls the destructor

    return 0;
}
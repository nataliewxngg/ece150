#include <iostream>

class C;
int main();

class C
{
public:
    C(double x = 0.0);
    C(int m, int n = 0);
    std::string about() const;
    ~C();
};

C::C(double x)
{
    std::cout << "Calling C(double)" << std::endl;
}

C::C(int m, int n)
{
    std::cout << "Calling C(int, int)" << std::endl;
}

C::~C()
{
    std::cout << "Calling ~C()" << std::endl;
}

std::string C::about() const
{
    return "Harmless";
}

int main()
{
    // creating an ARRAY of object C's
    C data[10]{{1}, {}, {5, 7}, {2.5}}; // i can create a C obj with no arguments ONLY BECAUSE i have default values in the constructor's arguments

    for (std::size_t i{0}; i < 10; ++i)
    {
        std::cout << data[i].about() << std::endl;
    }

    return 0; // destructor called on EACH C object in data
}
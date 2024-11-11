#include <iostream>
#include <cassert>

// Class Declarations
class Body;

// Function Declarations
int main();

// Class Definitions
class Body
{
public:
    // Member variables - every instance will have two vectors (of cap 3) and one double
    double position_[3]; // km
    double velocity_[3]; // km/h
    double mass_;        // kg
    // Each Body object will accumulate (8*3)+(8*3)+8 = 8*7 = 56 bytes

    // General rules of Classes
    // 1. class names are CAPITALIZED
    // 2. member variables SUFFIXED WITH _
};

double weight(Body b)
{
    // earth passes by VALUE - the 2 lines below DO NOT AFFECT earth's member variables
    // use & operator to force pass by reference if applicable - reduce amount of copying
    b.mass_ = 9;
    b.position_[2] = 100;
    return b.mass_ * 9.8;
}

Body changeMass(Body b)
{
    b.mass_ = 0;
    return b;
}

// Function definitions
int main()
{
    // create a Body *OBJECT*
    Body earth{{149.6e6, 0, 0}, {0, 107e3, 0}, 5.972e24};

    // accessing member variables
    std::cout << earth.mass_ << std::endl;
    std::cout << earth.position_[0] << std::endl;

    // assigning member variables
    for (std::size_t k{0}; k < 3; ++k)
    {
        earth.position_[k] += 0.1 * earth.velocity_[k];
    }

    // objects as arguments
    std::cout << weight(earth) << std::endl;
    std::cout << earth.mass_ << std::endl;        // unaffected
    std::cout << earth.position_[2] << std::endl; // unaffected

    // objects can be returned too
    earth = changeMass(earth);

    return 0;
}

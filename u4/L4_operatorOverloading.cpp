#include <iostream>

int main();

class Vector_3d;
class Vector_3d
{
public:
    // Member variables
    double x_;
    double y_;
    double z_;
};
std::string to_string(Vector_3d &u)
{
    return "x: " + std::to_string(u.x_) + "\ny: " + std::to_string(u.y_) + "\nz: " + std::to_string(u.z_);
}

// -------------------------------------

// you can overload every operator in C++ (arithmetic, bitwise, etc.) with new operands!
// eg. +, -, /, *, ==, <, >, !=, +=, -=, etc.

Vector_3d operator+(Vector_3d &u, Vector_3d &v) // THIS FUNCTION IS CALLED WHEN ADDING 2 VECTOR_3D OBJS
{
    return Vector_3d{u.x_ + v.x_, u.y_ + v.y_, u.z_ + v.z_}; // return an object like this! (notice there's no var name)
}
Vector_3d operator-(Vector_3d &v) // THIS FUNCTION IS CALLED WHEN -(VECTOR_3D OBJS)
{
    return Vector_3d{-v.x_, -v.y_, -v.z_};
}

// to get Vector_3d to work with std::cout!!!!!!
// eg. std::cout << v;

// std::cout is in class std::ostream
std::ostream &operator<<(ostream &out, Vector_3d &u) // NOTION QUESTION???????????????????????????????????
{
    out << "(" << u.x_ << ", " << u.y_ << ", " << u.z_ << ")";
    return out;
}

// -------------------------------------

int main()
{
    Vector_3d i{1, 0, 0};
    Vector_3d j{0, 1, 0};

    Vector_3d sum = i + j;
    std::cout << to_string(sum) << std::endl;

    std::cout << i;

    return 0;
}
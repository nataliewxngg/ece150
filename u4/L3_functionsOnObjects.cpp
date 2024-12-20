#include <iostream>

class Vector_3d;
class Array;
int main();

class Vector_3d
{
public:
    // Member variables
    double x_;
    double y_;
    double z_;
};

class Array
{
public:
    std::size_t capacity_;
    // double array_[capacity_]; // NOT ALLOWED - capacity_ is not defined at compile time
    double *array_;

    // PROBLEMS WITH THIS CLASS:
    // we have to check if it = nullptr for each function (since we can't modify/access unallocated arrays)
};

// -----------------------------

// Functions on Objects (examples)
// *** recall pass by reference is used to avoid copying large objects

double inner_product(Vector_3d const &u, Vector_3d const &v);
double norm(Vector_3d const &u);
bool equal(Vector_3d const &u, Vector_3d const &v);

double inner_product(Vector_3d const &u, Vector_3d const &v)
{
    return u.x_ * v.x_ + u.y_ * v.y_ + u.z_ * v.z_;
}
bool equal(Vector_3d const &u, Vector_3d const &v)
{
    return u.x_ == v.x_ && u.y_ == v.y_ && u.z_ == v.z_;
}
void mul_by(Vector_3d &v) // *** MUST pass by reference for functions modifying objects
{
    int c{3}; // scalar multiple
    v.x_ *= c;
    v.y_ *= c;
    v.z_ *= c;
}

// -----------------------------

// We can "return 2 values" by returning an object

int main()
{
    int n{18};
    std::cout << static_cast<double>(n) << std::endl; // 18 (a float)

    double l{19.8};
    std::cout << static_cast<int>(l) << std::endl; // 19 (an int)

    return 0;
}
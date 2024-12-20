#include <iostream>

// namespace natalie; // INCORRECT - declaration for namespace not necessary!
int main();
class Point;

namespace natalie
{
    int birthday(int const age);
    int birthday(int const age)
    {
        return age + 1;
    }
}

class Point
{
public:
    Point(int new_x, int new_y, int new_z);
    Point operator+(Point const &other);
    Point &operator+=(Point const &p);

private:
    int x_;
    int y_;
    int z_;
    friend std::ostream &operator<<(std::ostream &out, Point const &p);
};

Point::Point(int new_x, int new_y, int new_z) : x_{new_x}, y_{new_y}, z_{new_z}
{
}

Point Point::operator+(Point const &other)
{
    return Point{x_ + other.x_, y_ + other.y_, z_ + other.z_};
}

Point &Point::operator+=(Point const &p)
{
    *this = *this + p;
    return *this;
}

std::ostream &operator<<(std::ostream &out, Point const &p)
{
    out << "(" << p.x_ << ", " << p.y_ << ", " << p.z_ << ")";
    return out;
}

int main()
{
    std::cout << natalie::birthday(17) << std::endl; // 18

    Point p1{2, 3, 4};
    Point p2{3, 4, 5};

    p1 += p2;
    std::cout << p1 << std::endl;

    return 0;
}
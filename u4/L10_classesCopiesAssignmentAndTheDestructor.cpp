#include <iostream>

// Quick review

class Pair;
int main();
Pair f(Pair p);

class Pair
{
public:
    Pair(int const new_first, int const new_second);

private:
    int first_;
    int second_;
    friend std::ostream &operator<<(std::ostream &out, Pair const &p);
};

Pair::Pair(int const new_first, int const new_second) : first_{new_first}, second_{new_second}
{
    // empty constructor
}
std::ostream &operator<<(std::ostream &out, Pair const &p)
{
    out << "(" << p.first_ << "," << p.second_ << ")";
    return out;
}

int main()
{
    Pair p1{0, 1};
    Pair p2{2, 3};
    Pair p3{p1};
    std::cout << p3 << std::endl; // (0,1)

    p3 = p2;
    std::cout << p3 << std::endl; // (2,3)

    p3 = f(p3);
    std::cout << p3 << std::endl; // (4,5)

    return 0;
}

Pair f(Pair p)
{
    std::cout << p << std::endl;
    return Pair{4, 5};
}
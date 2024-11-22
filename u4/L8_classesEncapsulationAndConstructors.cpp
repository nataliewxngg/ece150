#include <iostream>
#include <cassert>

class Rational
{
public:
    // include info useful to EVERYONE

    Rational(); // constructor declaration
    Rational(int new_numer, int new_denom = 1);

    // member functions declaration
    int numer() const; // const disallows member function from changing the values of any member variables
    int denom() const;
    void numer(int new_numer);
    void denom(int new_denom);
    Rational abs() const;

    Rational operator+(Rational const q) const;
    // int + rational operator cannot be overloaded as we would have to define a member function in int class if so
    // instead, this should be done NOT as a member function but a general one (line 135)
    Rational operator-() const;
    bool operator==(Rational const q) const;

private:
    // include info useful to AUTHOR only

    // only accessible (and initializable) by constructors, member functions, destructors, and friends
    int numer_; // member variables initialized to default values (ie. 0, null, false) by default
    int denom_;

    // helpers declaration - meant to help member functions, not the user
    void normalize();

    static int gcd(int m, int n); // static member functions CANNOT 1. access non-static member variables, 2. call any non-static member functions

public:
private:
public:
private:
private:
    // can include as many labels as preferred (as seen above)
};

Rational::Rational() : numer_{0}, // constructor: no return type, same name as class
                       denom_{1}
{
    // constructor definition
}

// lines 18-22 is same as...
// Rational::Rational()
// {
//     numer_ = 0;
//     denom_ = 1;
// }

Rational::Rational(int new_numer, int new_denom) : numer_{new_numer}, denom_{new_denom} // another constructor
{
    if (denom_ == 0)
        throw std::domain_error{"The denominator must be nonzero"};

    normalize(); // member functions called in constructors/member functions/destructors are assumed to be CALLED ON THE OBJ BEING CREATED
}

// member function definitions
int Rational::numer() const
{
    return numer_;
}

int Rational::denom() const
{
    return denom_;
}

void Rational::numer(int new_numer)
{
    numer_ = new_numer;
    normalize();
}

void Rational::denom(int new_denom)
{
    if (new_denom == 0)
    {
        throw std::domain_error{"the denominator must be non-zero"};
    }

    denom_ = new_denom;
    normalize();
}

Rational Rational::abs() const
{
    return Rational{std::abs(numer_), denom_};
}

// helper function
void Rational::normalize()
{
    assert(denom_ != 0);

    if (denom_ < 0)
    {
        numer_ = -numer_;
        denom_ = -denom_;
    }

    // int divisor{gcd(numer_,denom_)};
    // numer_ /= divisor;
    // denom_ /= divisor;
}

// operator overloading
std::ostream &operator<<(std::ostream &out, Rational const &p)
{
    out << p.numer();
    if (p.denom() != 1)
    {
        out << "/" << p.denom();
    }
    return out;
}

Rational Rational::operator+(Rational const q) const
{
    return (Rational{
        numer_ * q.denom_ + q.numer_ * denom_,
        denom_ * q.denom_});
}

Rational Rational::operator-() const
{
    return Rational{-numer_, denom_};
}

Rational operator+(int const n, Rational const &q)
{
    return q + n;
}

bool Rational::operator==(Rational const q) const
{
    return numer_ == q.numer_ && denom_ == q.denom_;
}

int main()
{
    Rational q{};
    Rational r{-2, 9};

    std::cout
        << q.numer() << "/" << q.denom() << std::endl;
    std::cout << q << std::endl; // uses the &operator<< function

    std::cout << r << std::endl;
    std::cout << r.abs() << std::endl;

    q = r;        // VALUES of member variables are COPIED over (not pass by reference surprisingly)
    q.numer(100); // only changes numerator of q
    r.numer(200); // only changes numberator of r
    std::cout << q << std::endl;
    std::cout << r << std::endl;

    return 0;
}

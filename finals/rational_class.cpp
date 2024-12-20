#include <iostream>
#include <cassert>

// Rational class
class Rational;
int main();
std::ostream &operator<<(std::ostream &out, Rational const &r);
Rational operator+(int const n, Rational const &r); // must be implemented this way, since LHS is an int

class Rational
{
public:
    // Constructors
    Rational();                                 // #1
    Rational(int new_numer, int new_denom = 1); // #2

    // Member Functions
    int numer() const;
    int denom() const;
    void numer(int new_numer);
    void denom(int new_denom);

    Rational abs() const;

    Rational operator+() const;
    Rational operator-() const;
    Rational operator+(Rational const &rhs) const;

private:
    int numer_;
    int denom_;

    // Helper functions
    void normalize();
    static int gcd(int m, int n);
};

// Constructor definition
Rational::Rational() : numer_{0}, denom_{1}
{
    // empty constructor - normalize here if necessary
}

Rational::Rational(int new_numer, int new_denom) : numer_{new_numer}, denom_{new_denom}
{
    if (denom_ == 0)
        throw std::domain_error{
            "The denominator must not equal to 0"};

    normalize(); // called on the same object
}

// Member functions definitions
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
        throw std::domain_error{
            "Denominator must not equal to 0"};
    }
    denom_ = new_denom;
    normalize();
}

Rational Rational::abs() const
{
    return Rational{std::abs(numer_), denom_};
}

Rational Rational::operator+() const
{
    return *this;
}

Rational Rational::operator-() const
{
    return Rational{-numer_, -denom_};
}

Rational Rational::operator+(Rational const &rhs) const
{
    Rational out{(numer_ * rhs.denom_) + (rhs.numer_ * denom_), denom_ * rhs.denom_};
    out.normalize();

    return out;
}

// Helper functions definitions
void Rational::normalize()
{
    assert(denom_ != 0);

    if (denom_ < 0)
    {
        numer_ = -numer_;
        denom_ = -denom_;
    }

    // more normalization work
}

// ostream operator
std::ostream &operator<<(std::ostream &out, Rational const &r)
{
    if (r.denom() == 1)
    {
        out << r.numer();
    }
    else
    {
        out << r.numer() << "/" << r.denom();
    }
    return out;
}

int main()
{
    Rational frac_1{};     // calls constructor #1
    Rational frac_2{3};    // calls constructor #2
    Rational frac_3{1, 4}; // calls constructor #3
    std::cout << frac_1 << std::endl;
    std::cout << frac_2 << std::endl;
    std::cout << frac_3 << std::endl;

    return 0;
}

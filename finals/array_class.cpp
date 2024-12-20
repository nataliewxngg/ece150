#include <iostream>

class Array;
int main();

class Array
{
public:
    // constructors
    Array(std::size_t const new_capacity, double const value = 0.0);
    Array(Array const &original);
    Array(Array &&original) = delete;
    // destructor
    ~Array();
    Array &operator=(Array const &rhs);
    Array &operator=(Array &&rhs) = delete;

    // member functions
    std::size_t capacity() const;

    double operator[](std::size_t i) const;
    double &operator[](std::size_t i);

    double at(std::size_t i) const;
    double &at(std::size_t i);

private:
    std::size_t capacity_;
    double *array_;
};

// Constructor definition
Array::Array(std::size_t const new_capacity, double const value) : capacity_{new_capacity}, array_{new double[capacity_]}
{
    for (std::size_t i{0}; i < capacity_; ++i)
    {
        array_[i] = value;
    }
}

Array::Array(Array const &original) : capacity_{original.capacity_}, array_{new double[capacity_]}
{
    for (std::size_t i{0}; i < capacity_; ++i)
    {
        array_[i] = original.array_[i];
    }
}

// Destructor definition
Array::~Array()
{
    for (std::size_t i{0}; i < capacity_; ++i)
    {
        array_[i] = 0.0;
    }
    capacity_ = 0; // DON'T FORGET!!!
    delete[] array_;
    array_ = nullptr;
}

Array &Array::operator=(Array const &rhs)
{
    Array copy{rhs};

    std::swap(capacity_, copy.capacity_);
    std::swap(array_, copy.array_);

    return *this;
}

// Member functions definition
std::size_t Array::capacity() const
{
    return capacity_;
}

double Array::operator[](std::size_t i) const
{
    return array_[i];
}
double &Array::operator[](std::size_t i)
{
    return array_[i];
}

double Array::at(std::size_t i) const
{
    if (i >= capacity_)
        throw std::out_of_range{"Index is equal to or greater than the capacity of the array!"};
    return array_[i];
}
double &Array::at(std::size_t i)
{
    if (i >= capacity_)
        throw std::out_of_range{"Index is equal to or greater than the capacity of the array!"};
    return array_[i];
}

int main()
{
    Array data{10};

    return 0;
}
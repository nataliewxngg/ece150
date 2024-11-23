#include <iostream>
#include <string>

class Array;
int main();

class Array
{
public:
    Array(std::size_t const new_capacity, double const value = 0.0);
    std::size_t capacity() const;

    ~Array(); // destructor: used to clean up any dynamically allocated memory
    //           - takes no arguments
    //           - NEVER EXPLICITLY CALLED (compiler schedules the calls)

    // ---------------------------------------

    // ****** in general
    // if your class dynamically allocates memory, include all this:
    // (move constructors are called when the compiler determines that the destructor will be called on the rhs/original obj right after assignment finishes)

    // copy constructor
    Array(Array const &original_array);
    // move constructor
    Array(Array &&original) = delete;

    // assignment copy constructor
    Array &operator=(Array const &rhs);
    // assignment move constructor
    Array &operator=(Array &&rhs) = delete;

    // ---------------------------------------

    // to access the array
    // (second version is called in general UNLESS the obj being called on is const)
    double operator[](std::size_t k) const;
    double &operator[](std::size_t k);

    double at(std::size_t k) const;
    double &at(std::size_t k);

private:
    // 16 bytes allocated for both member variables
    std::size_t capacity_;
    double *array_;
};

Array::Array(std::size_t const new_capacity, double const value) : capacity_{new_capacity}, array_{new double[capacity()]}
{
    for (std::size_t i{0}; i < capacity_; ++i)
    {
        array_[i] = value;
    }
}

Array::~Array()
{
    delete[] array_;
    capacity_ = 0;
    array_ = nullptr;
}

std::size_t Array::capacity() const
{
    return capacity_;
}

// copy constructor
Array::Array(Array const &original) : capacity_{original.capacity_}, array_{new double[original.capacity_]}
{
    for (std::size_t i{0}; i < original.capacity_; ++i)
    {
        array_[i] = original.array_[i];
    }
}

// assignment copy constructor
Array &Array::operator=(Array const &rhs)
{
    Array copy{rhs}; // calls the copy constructor

    // swaps the address/values stored in copy with rhs
    std::swap(capacity_, copy.capacity_);
    std::swap(array_, copy.array_);

    return *this; // returns the object this was called on (lhs)
}

double Array::operator[](std::size_t k) const
{
    return array_[k];
}
double &Array::operator[](std::size_t k)
{
    return array_[k];
}

double Array::at(std::size_t k) const
{
    if (k >= capacity_) // range checking for the "at" member functions needed
    {
        throw std::out_of_range{"The capacity is " + std::to_string(capacity_) + " but received " + std::to_string(k)};
    }
    return array_[k];
}

// int main()
// {
//     Array data{10};
//     return 0; // ~Array() is called here - since data goes OUT OF SCOPE
// }

int main()
{
    Array data{13};
    Array copy{data};

    std::cout << data.capacity() << std::endl;
    std::cout << copy.capacity() << std::endl;

    return 0;

    // this will result in an error since the objects contain a DYNAMICALLY ALLOCATED MEMORY
    // 1 object will be deallocated first, but then the next object will try to deallocate that same already deallocated memory, resulting in an error...

    // UNLESS...... there is a copy constructor
}

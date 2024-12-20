#include <iostream>

int main();
void print_arr(int const arr[], std::size_t const capacity);

void print_arr(int const arr[], std::size_t const capacity)
{
    if (capacity == 0)
        return;

    std::cout << arr[0];

    for (std::size_t i{1}; i < capacity; ++i)
    {
        std::cout << ", " << arr[i];
    }
    std::cout << std::endl;
}

/*
1. [3 marks] Write a C++ function that finds the largest integer less than or equal to the square root of n
for a given unsigned long n. You may not use any floating-point numbers or calculations.
*/
unsigned long sqrt(unsigned long n);
unsigned long sqrt(unsigned long n)
{
    unsigned long out{};
    while (out * out <= n)
        ++out;
    --out;
    return out;
}

/*
 [3 marks] Write a C++ function that calculates and returns the following sum:
(1) + (1 + 4) + (1 + 4 + 9) + (1 + 4 + 9 + 16) + ··· + (1 + 4 + 9 + ··· + n^2)
where n is an unsigned int parameter of the function. If n is zero, the result is also zero.
*/
unsigned int square_sum(unsigned int n);
unsigned int square_sum(unsigned int n)
{
    if (n == 0)
        return 0;
    unsigned int out{};
    for (unsigned int i{1}; i <= n; ++i)
    {
        for (unsigned int k{1}; k <= i; ++k)
        {
            out += k * k;
        }
    }
    return out;
}

/*
3. [6 marks] Write a C++ function that “rotates” an int array to the right, by moving the first entry of
the array to the second, the second entry to the third, and so on until it moves the last entry to the first
position. The function is passed the array and the capacity of the array, and the specified operation is
performed on that array. Give the function and parameters appropriate names and determine the
return type, if necessary.
*/
void rotate_array(int arr[], std::size_t const capacity);
void rotate_array(int arr[], std::size_t const capacity)
{
    int tmp{arr[capacity - 1]};

    for (std::size_t i{capacity - 1}; i > 0; --i)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = tmp;
}

/*
4. [10 marks] Write a C++ function that takes two unsigned short as parameters and interleaves the
bits into an unsigned int that is returned. For example, the two short integers m and n
m: 0000000000000001 n: 1111111111111110
would return the unsigned int
01010101010101010101010101010110
That is, the even bits (note that we start counting with zero (which is even) with the least-significant (the
right-most) bit) are the bits from n and the odd bits are the bits from m.
*/
unsigned int mingle(unsigned short m, unsigned short n)
{
    unsigned int m_1{m};
    unsigned int n_1{n};
    unsigned int out{};
    unsigned int mask{1};

    // do n first
    for (int i{0}; i < 16; ++i)
    {
        out ^= mask & n_1;
        n_1 <<= 1;
        mask <<= 2;
    }

    // do m
    mask = 2;
    m_1 <<= 1;
    for (int i{0}; i < 16; ++i)
    {
        out ^= mask & m_1;
        m_1 <<= 1;
        mask <<= 2;
    }

    return out;
}

/*
6. [10 marks] In the course, and in the previous question, you have seen the implementation of a binary
search. Instead, here you will implement a ternary search, as follows.
The function
 bool ternary( int val, int arr[], std::size_t m, std::size_t n );
will search for value val in the sorted array arr from entry m to entry n, inclusive. You may assume the
array is sorted and that m <= n.
 If there are seven or fewer entries to search, then just do a linear search: check the entries from
arr[m] to arr[n] and check if any of these equals to val – return true if one equals to val
and false otherwise.
 If there are eight or more entries to be searched, choose an entry close to one third of the
interval, and choose an entry close to the second third of the interval.
o If either of these are the value you are searching for, return true.
o Otherwise, recursively call ternary() searching the first third, second third, or third
third, as appropriate.
To search for a value in an array with capacity cap, the first call to ternary() is with m = 0 and n =
cap - 1, which searches the entire array.
For example, if m = 15 and n = 34, then we could check entries 21 and 27, and if neither of these entries
equaled val, then we would recursively call ternary() with the arguments (15, 20), (22, 26), or (28,
34), as appropriate. We don’t require you to get exactly 21 or 27 in this case, but your calculation should
at least approximately divide the interval m to n into three approximately equal sub-intervals
*/
bool ternary(int val, int arr[], std::size_t m, std::size_t n)
{
    if (n - m < 7)
    {
        // perform linear search
        for (std::size_t i{m}; i <= n; ++i)
        {
            if (arr[i] == val)
                return true;
        }
        return false;
    }
    std::size_t left{(m + n) / 3};
    std::size_t right{2 * ((m + n) / 3)};

    if (arr[left] == val || arr[right] == val)
        return true;
    else if (arr[left] > val)
        ternary(val, arr, m, (m + n) / 3);
    else if (arr[right] > val && arr[left] < val)
        ternary(val, arr, left, right);
    else
        ternary(val, arr, 2 * ((m + n) / 3), n);
}

/*
#7
*/
class Matrix;
class Matrix
{
public:
    Matrix(unsigned int m, unsigned int n);
    Matrix(Matrix const &orig);

    ~Matrix();

    double &operator()(unsigned int i, unsigned int j);

    Matrix &operator*=(double c);

private:
    unsigned int m_;
    unsigned int n_;
    double *array_;
};

Matrix::Matrix(unsigned int m, unsigned int n) : m_{m}, n_{n}, array_{new double[m * n]}
{
    for (std::size_t i{0}; i < (m * n); ++i)
        array_[i] = 0.0;
}

Matrix::Matrix(Matrix const &orig) : m_{orig.m_}, n_{orig.n_}, array_{new double[m_ * n_]}
{
    for (std::size_t i{0}; i < m_ * n_; ++i)
        array_[i] = orig.array_[i];
}

Matrix::~Matrix()
{
    for (std::size_t i{0}; i < m_ * n_; ++i)
        array_[i] = 0.0;
    delete[] array_;
    array_ = nullptr;
}

Matrix &Matrix::operator*=(double c)
{
    for (std::size_t i{0}; i < m_ * n_; ++i)
        array_[i] *= c;
    return *this;
}

/*
Implement a new member function void interpolate() that replaces the array of the current
capacity cap_ with a new array that has capacity 2 * cap_ - 1 where:
1. The entries in the original array are copied to each alternate entry of the new array starting with
index 0.
2. The intermediate entries are assigned the average of the two entries surrounding it.
If the capacity of the array is 0 or 1, interpolate() does nothing.
*/
class Array;
class Array
{
public:
    Array(std::size_t cap);
    Array(Array const &orig);
    ~Array();
    void interpolate();

private:
    std::size_t cap_;
    double *array_;
};

void Array::interpolate()
{
    if (cap_ != 0 && cap_ != 1)
    {
        double *old_array{array_};

        array_ = new double[2 * cap_ - 1]{};
        for (std::size_t i{0}; i < cap_; ++i)
        {
            array_[2 * i] = old_array[i];
        }
        for (std::size_t i{1}; i < cap_; i += 2)
        {
            array_[i] = (array_[i - 1] + array_[i + 1]) / 2;
        }

        delete[] old_array;
        old_array = nullptr;
    }
}

/*
#9
*/
class Node;
class Linked_list;
class Node
{
public:
    double value() const;
    Node *get_next() const;
    void set_next(Node *p_new_next);

private:
    double value_;
    Node *p_next_;
};

class Linked_list
{
public:
    void make_sorted();

private:
    std::size_t count_;
    Node *p_head_;
};

void Linked_list::make_sorted()
{
    if (p_head_ != nullptr)
    {
        Node *prev_node{p_head_};

        for (Node *p{p_head_->get_next()}; p != nullptr; p = p->get_next())
        {
            if (p->value() <= prev_node->value())
            {
                // remove p
                prev_node->set_next(p->get_next());
                delete p;
                p = prev_node;
            }
            else
                prev_node = p;
        }
    }
}

int main()
{
    std::cout << sqrt(36) << std::endl;
    std::cout << 1 + 1 + 4 + 1 + 4 + 9 << " = " << square_sum(3) << std::endl;

    int arr[5]{1, 2, 3, 4, 5};
    print_arr(arr, 5);
    rotate_array(arr, 5);
    print_arr(arr, 5);

    std::cout << mingle(1, 0b1111111111111110) << std::endl;
    std::cout << 0b01010101010101010101010101010110 << std::endl;

    return 0;
}
#include <iostream>
class A;
class B;
class C;
class D;

class A
{
public:
    virtual void print() const;
};
void A::print() const
{
    std::cout << "A";
}
class B : public A
{
public:
    void print() const override;
};
void B::print() const
{
    std::cout << "B";
}
class C : public A
{
public:
    void print() const override;
};
void C::print() const
{
    std::cout << "C";
}
class D : public B
{
};

int main()
{
    A a{};
    B b{};
    C c{};
    D d{};
    A *data[4]{&a, &b, &c, &d};
    for (std::size_t k{0}; k < 4; ++k)
    {
        data[k]->print(); // Line 1
    }
    return 0;
}
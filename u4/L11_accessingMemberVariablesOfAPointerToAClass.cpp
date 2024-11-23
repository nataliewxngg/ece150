#include <iostream>

class G;
int main();

class G
{
public:
    G(int n);
    G(G const &original);
    ~G();
    int retrieve() const;

private:
    int value_;
};

G::G(int new_value) : value_{new_value}
{
    std::cout << "Calling G(int)" << std::endl;
}
G::G(G const &original) : value_{original.value_}
{
    std::cout << "Calling G(G const &)" << std::endl;
}
G::~G()
{
    std::cout << "Calling ~G()" << std::endl;
}
int G::retrieve() const
{
    return value_;
}

int main()
{
    G item{42};
    G *p_item{new G{91}};

    std::cout << item.retrieve() << std::endl;
    std::cout << p_item->retrieve() << std::endl; // use -> to access a member variable/func within a pointer to an objects

    delete p_item; // must deallocate pointers to objs on our own
    p_item = nullptr;

    // pointer to an array of G objects
    G *a_items{new G[3]{{101}, {102}, {103}}}; // a pointer to an array is just the array itself
    for (std::size_t i{0}; i < 3; ++i)
    {
        std::cout << a_items[i].retrieve() << std::endl;
    }

    delete[] a_items;
    a_items = nullptr;

    // array of pointers of objects G
    G *array[5]{};
    for (std::size_t i{0}; i < 5; ++i)
    {
        array[i] = new G{i};
    }
    std::cout << array[0]->retrieve() << std::endl;

    // ************************
    // RULE
    // if printing a var/array entry produces an address, then use the ARROW OPERATOR ->
    // otherwise, use the dot operator .

    // and you must call delete on any p_name variables (assuming all pointers follow the naming convention)

    return 0;
}

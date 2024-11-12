#include <iostream>

// examples of OBJECTS in the std namespace includes...
// 1. cout
// 2. clog
// 3. endl

// Creates the namespace natalie_namespace
namespace natalie_namespace
{
    // Namespaces ensure that changes in one namespace DOES NOT affect anything in another

    // eg. suppose you have a sec() function and cmath adds the sec() function into their library too,
    //     this will either ...
    //      1. break your code
    //      2. call the wrong sec() function

    std::string say_hi(std::string name); // will need to be called as natalie_namespace::say_hi(...);

    std::string say_hi(std::string name)
    {
        return "hi " + name;
    }
}

int main();
int main()
{
    std::cout << natalie_namespace::say_hi("poopalie");
    return 0;
}
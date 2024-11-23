#include <iostream>
class Vector_3d;
class Vector_3d
{
public:
    // q: why encapsulate data when values don't need to be restricted?
    //    (can be anything - and so we should allow users to modify them)
    // ans: changing the representation of the class in the future may break the user's code

    // therefore, it is important to restrict access to member variables even if it seems unnecessary

    // terms:
    // 1. interface = member functions that allow user to access/manipulate an instance
    // 2. inlining = replacing function call with function definition (if function is short)
    double x;
    double y;
    double z;
};

int main();
int add(int n, int m);

int add(int n, int m)
{
    return n + m;
}

int main()
{
    int sum{};

    sum = add(2, 3);
    sum = 2 + 3; // inlining of line 32

    return 0;
}
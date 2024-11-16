#include <iostream>

int main();
int main()
{
    // Normal Form
    // it is of best practice to "normalize" objects - so that data is consistent and not redundant
    // (so that objects with different parameters that are essentially the same are represented the same way)

    // We also want to prevent users from accessing member variables but to use member functions instead (so that objects remain normalized and correct)

    // ------------------------------------------

    // To avoid problems (eg. wild pointers, null pointers, memory leaks),
    // deal with the creation of the object from CREATION, EXISTENCE, to DESTRUCTION

    // Terminology:
    // 1. Constructors... deal with initialization
    // 2. Member Functions... deal with accessing and manipulating
    // 3. Destructors... deal with clean-up (ie. deallocation)

    // ------------------------------------------

    // Encapsulation: protection of data (!= security)

    return 0;
}
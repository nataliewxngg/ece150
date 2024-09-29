#include <iostream>

int average(unsigned const int MARK) { // const in parameter!
    return MARK+2;
}

int main() {

    // Initializing Constants (aka. read-only variables) -> Rules
    // - name them UPPERCASE for good practice!
    // - must be initialized with a value
    const std::string NAME{"Natalie"};
    const int NUM_OF_TOES{10};

    std::cout<<average(98);

    return 0;
}
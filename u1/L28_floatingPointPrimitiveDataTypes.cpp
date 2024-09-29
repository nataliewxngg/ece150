#include <iostream>

int main() {

    // Floating Point Primitive Datatype Sizes
    std::cout<<"Data types          # of bytes (in ascending order)"<<std::endl;

    std::cout<<"float:               " << sizeof(float) << std::endl;     // 4 (32 bits) <- 7 max precision
    std::cout<<"double:              " << sizeof(double) << std::endl;// 8 (64 bits) <- 16 max precision

    // Weaknesses of fixed precision
    float x{1.23};
    float y{0.00000000000000000000000000000028394};
    
    // 1. 
    std::cout<<((x+y)==x)<<std::endl; // true but should be false since y!=0

    float z{1.2300000004};
    // 2.
    std::cout<<((x-z)==0)<<std::endl; // true but should be false since x!=z so x-z should not =0

    

    return 0;
}
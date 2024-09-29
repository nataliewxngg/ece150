#include <iostream>

// RULE: parameters with default values must be placed AT THE END!
int sum(int i, int j,int k = 5, int m = 7, int n = 11) { // i and j are required variables
                                                          // but parameters k, m, and n have default values
    return i+j+k+m+n;
}

int main() {
    std::cout<<sum(2,4)<<std::endl;
    std::cout<<sum(2,4,0,0,0)<<std::endl;

    return 0;
}
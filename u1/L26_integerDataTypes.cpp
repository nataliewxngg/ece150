#include <iostream>

int main() {
    std::cout<<"Data types          # of bytes (in ascending order)"<<std::endl;
    std::cout<<"char:               " << sizeof(char)<<std::endl;       // 1 (8 bits)
    std::cout<<"short:              " << sizeof(short)<<std::endl;      // 2 (16 bits)
    std::cout<<"int:                " << sizeof(int) <<std::endl;       // 4 (32 bits)
    std::cout<<"long:               " << sizeof(long) << std::endl;     // 4 (32 bits) <- 64 on most compilers
    std::cout<<"long long:          " << sizeof(long long) << std::endl;// 8 (64 bits)

    unsigned short m{0b1000001101001101};
    unsigned short n{0b0111111000111110};
    std::cout<<m<<std::endl; // 33613
    std::cout<<n<<std::endl; // 32318
    m+=n;
    std::cout<<m<<std::endl; // 395 <- additional carries are ignored 

    short m1{-0b0111110010110011}; // same as signed 1000001101001101 <- 2s complement 
    short n1(0b0111111000111110);
    m1+=n1; //-31923 + 31318
    std::cout<<m1<<std::endl; // 395

    return 0;
}
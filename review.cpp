#include <iostream>
#include <string> // to declare strings
#include <cassert> // for assertions

int main();
bool is_prime(int n);
int reset_passByRef(int &n);
void deallocate(int *arr, const std::size_t cap);

void deallocate(int *arr, const std::size_t cap) {
    for (std::size_t k{0}; k < cap; ++k) {
        arr[k] = 0;
    }
    delete[] arr; // deallocate memory
    arr = nullptr; // forget this address
}

int reset_passByRef(int &n) {
    n = 0;
    return n;
}

bool is_prime(int n = 0) { // parameters w/ default values must be placed @ end (l30)
    if (n <= 1) return false;
    for (std::size_t i{2}; i < n; ++i) {
        if (n%i == 0) return false;
    }
    return true;
}

int main() {
    std::string name{};
    const int AGE{8/3}; // 2 (dumb rounding)
    const float AGE_EQUALSTO{8.0/3}; // 2.66667
    std::cout << AGE_EQUALSTO << std::endl;

    // register as nw to access the program
    std::cout << "\nEnter your name: ";
    std::cin >> name;
    assert(name == "nw");;

    // --------------------------------------------- for loop

    // IS N PRIME?
    std::cout << "\n" <<is_prime(13) << std::endl; // 1
    std::cout << is_prime(14) << std::endl; // 0

    while (true) {
        std::cout << std::endl;
        break;
        std::cout <<std::endl;
    }

    // ---------------------------------------------- do while

    // PRINT 1-10
    int count{0};
    do {
        std::cout << ++count << std::endl;
    } while (count < 10);

    // ---------------------------------------------- bin and hex rep.s

    char bin{0b1010};
    char hex{0xA};
    std::cout << "\n" << bin << std::endl; // 10
    std::cout << hex << "\n" << std::endl; // 10
    // signed bit (2s complement)
    // 1 = negative
    // 0 = positive

    // char - 1 byte *
    // short - 2 bytes *
    // int - 4 bytes *
    // long - 4 bytes
    // long long - 8 bytes

    // float - 4 bytes
    // double - 8 bytes

    // bitwise and bitshift operators - OPERATIONS MUST BE BRACKETED
    char a{0b1011};
    char b{0b0001};
    std::cout << "a & b (AND) = " << (a&b) << std::endl; // 0b0001 = 1
    std::cout << "a | b (OR) = " << (a|b) << std::endl; // 0b1011 = 11
    std::cout << "a ^ b (XOR) = " << (a^b) << std::endl; // 0b1010 = 10
    std::cout << "a << 2 = " << (a << 2) << std::endl; // 0b101100 = 32+12 = 44
                                                       // (would still be positive when we do a<<4 (=0b10110000)
                                                       // since bitshift operator will promote it to an int)
    std::cout << "a >> 2 = " << (a>>2) << "\n" << std::endl; // 0b10 = 2

    // &=, |=, ^=, <<=, >>=

    // ---------------------------------------------- references
    int n{1};
    int &m{n}; // m is a reference to n

    n=21;
    std::cout << "n: " << n << "; m: " << m << std::endl; // n: 21, m: 21
    m=8;
    std::cout << "n: " << n << "; m: " << m << std::endl; // n: 8, m: 8

    reset_passByRef(n);
    std::cout << "n: " << n << "; m: " << m << "\n" << std::endl; // n: 0, m: 0

    // ---------------------------------------------- arrays

    const std::size_t cap{5};
    std::string arr[cap]{"html","css","js"}; // capacity MUST be included, but initial values are optional
    for (int i{0}; i < 5; ++i) {
        std::cout << arr[i] << std::endl; 
    } 
    // arr[3] and arr[4] are EMPTY STRINGS (not null nor undefined)
    std::cout << (arr[4] == "") << std::endl; // 1 (true)
   
    arr[-1] = "python";
    std::cout << arr[-1] << std::endl;

    const int primes[10]{2, 3, 5, 7, 11, 13, 17, 19, 23, 25}; // cannot modify

    // ---------------------------------------------- c-style strings

    char cstr[100]{'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'}; // terminated by the null '\0' character
    std::cout << cstr << std::endl; 

    // ----------------------------------------------- addresses and pointers

    int num{2};
    int *p_num{&num}; // stores address of num

    int hi_arr[cap]{3,2,1};
    int *p_hi_arr{hi_arr}; // <- variable that stores type arr stores the ADDRESS of the first element

    *p_num = 3;
    std::cout << "\n" << "num: " << num << "; *p_num: " << *p_num << std::endl; // n: 3, p_n: 3

    std::cout << "hi_arr: " << hi_arr << "; p_hi_arr: " << p_hi_arr << "; &hi_arr[0]: " << &hi_arr[0] << std::endl; // addresses of num and hi_arr[0]

    // ----------------------------------------------- dynamic allocation

    int *p_wawa;
    p_wawa = new int{2};
    std::cout << "\np_wawa: " << p_wawa << std::endl;
    std::cout << "*p_wawa: " << *p_wawa << "\n" << std::endl;

    // deallocate
    delete p_wawa; // unallocate address
    p_wawa = nullptr; // forget this address

    // for arrays
    int *dyn_arr{new int[cap]{}};
    deallocate(dyn_arr, cap);
    
    return 0;
}
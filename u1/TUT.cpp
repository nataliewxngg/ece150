#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v(12);
    // std::vector<double> data(10); // 0 0 0 0 0 0 0 0 0 0

    std::vector<double> data{3.5, 2.7, 9.2, 3.2, 4.6, 9.8, 2.5, 1.7, 8.9, 5.4};

    std::cout << "size: " << v.size() << std::endl;

    for (auto k : data)
    {
        std::cout << k << " ";
    }
    std::cout << std::endl;

    std::sort(data.begin(), data.end()); // ascending sorts
    for (auto k : data)
    {
        std::cout << k << " ";
    }
    std::cout << std::endl;

    for (int k{0}; k < data.size(); ++k)
    {
        data[k] = 0.1 * k;
    } // 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0

    for (auto k : data)
    {
        std::cout << k << " ";
    } // displays every value in the vector data
    std::cout << std::endl;

    auto itr{data.begin()};
    std::cout << *itr << std::endl; // 0 <- iterator at index 0
    *itr = 3.14;
    std::cout << *itr << std::endl;    // 3.14
    std::cout << data[0] << std::endl; // 3.14

    ++itr;
    std::cout << *itr << std::endl; // 0.1 <- iterator at index 1

    for (auto it{data.begin()}; it != data.end(); ++it)
    {
        std::cout << *it << " ";
    } // iterate through the vector using an iterator

    return 0;
}
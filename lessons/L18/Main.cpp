#include <iostream>
#include <string>

int get_value_no_less_than(std::string text, int lower_bound)
{
    int num;
    do
    {
        std::cout << text;
        std::cin >> num;
    } while (num < lower_bound);
}

int main();

int main()
{
    get_value_no_less_than("dkjfalj", 3);
    return 0;
}
#include <iostream>

int main();

int main()
{
    int num{};
    int guess{};

    std::cout << "FOR PLAYER 1: Enter a number: ";
    std::cin >> num;

    std::cout << "FOR PLAYER 2: Guess!: ";
    std::cin >> guess;

    while (guess != num)
    {
        std::cout << "INCORRECT! Guess again!: ";
        std::cin >> guess;
    }
    std::cout << "You got it! :)" << std::endl;

    return 0;
}
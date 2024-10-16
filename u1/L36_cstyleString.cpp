#include <iostream>

int main();

int main()
{
    char phrase[100]{'G', 'o', 'o', 'd', ' ', 'd', 'a', 'y'};
    char phrase_2[4]{'m', 'e', 'o', 'w'};

    std::cout << phrase_2 << std::endl; // goes on to phrase because it's the subsequent bytes in memory (below phrase_2 in call stack)

    for (int i{0}; true; ++i)
    {
        if (phrase[i] == '\0')
        {
            std::cout << i << std::endl;
            break;
        }
    }
}
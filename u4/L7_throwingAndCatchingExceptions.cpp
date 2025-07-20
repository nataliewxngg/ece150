#include <iostream>
#define NDEBUG // to TURN ASSERTIONS OFF (must be before #include cassert)
#include <cassert>

int main();

int n_must_be_pos(int n)
{
    if (n < 0)
        throw std::domain_error{"n is negative!"}; // "n is negative!" will be returned when calling e.what();
    else
    {
        return n;
    }
}

int main()
{
    assert(0 != 0); // Issue with assertions: Automatically terminates the user's program

    // ---------------------------------------

    // Throw an exception:  signal there is a problem(s)
    // Catch an exception:  handle the problem(s) - and allows the program to continue executing

    // eg. (throwing an exception)
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    if (n < 0)
    {
        throw std::domain_error{"Cannot compute the square root of " + std::to_string(n)};
    }
    else
    {
        //... proper function
    }

    // eg. (catching an exception)
    try
    {
        std::cout << n_must_be_pos(5) << std::endl;
        std::cout << n_must_be_pos(-1) << std::endl;
        std::cout << n_must_be_pos(3) << std::endl; // this will never execute since line 44 results in an exception catch
    }
    catch (std::domain_error &e)
    {
        std::cout << "An exception was caught" << std::endl;
        std::cout << " - the error string was \"" << e.what() << "\"" << std::endl;
    }
    catch (...) // catch(...) catches ALL types of exceptions
    {
        std::cout << "An exception was caught" << std::endl;
    }

    // CONTINUE ON RANGE ERROR - EXCEPTION CLASS DOESN'T MATCH

    return 0;
}
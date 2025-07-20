#include <iostream>

// Function declarations
int main();

// Function definitions
int main()
{
    ///////////////////////////////
    // Printing literal integers //
    ///////////////////////////////

    std::cout
        << "Integers are printed as"
        << " one would expect"
        << std::endl;

    // This prints the string and the
    // number 42.
    //  - Note that the string has a
    //    space right before the
    //    closing quote, as
    //    otherwise, the '42' would
    //    be printed right next to
    //    the 's' in "is".
    std::cout
        << "The answer to the ultimate"
        << " question is "
        << +42 << std::endl;

    std::cout << "32 - 42 = "
              << -10 << std::endl;

    std::cout << std::endl;

    //////////////////////
    // Printing literal //
    // characters      //
    /////////////////////

    // This prints individual letters
    // and numbers
    //   - These are known as
    //     'alphanumeric' characters.
    std::cout << 'a' << 'b' << 'z'
              << 'A' << 'B' << 'Z'
              << '1' << '2' << '0'
              << std::endl;

    // This prints out the individual
    // characters for most of the
    // symbols on the keyboard:
    std::cout << '`' << '~' << '!'
              << '@' << '#' << '$'
              << '%' << '^' << '&'
              << '*' << '(' << ')'
              << '-' << '_' << '='
              << '+' << '[' << ']'
              << '{' << '}' << '|'
              << ':' << ';' << '"'
              << '.' << '<' << ','
              << '>' << '?'
              << std::endl;

    // Two characters specifically
    // must be 'escaped' in your
    // code so that the compiler
    // knows how to correctly
    // interpret them.
    std::cout << '\''
              << '\\'
              << std::endl;

    // There are a few special
    // characters that can also be
    // printed, including a tab
    // character
    //   - The size of a tab differs
    //     from platform to platform
    std::cout << 10 << '\t'
              << 4 << std::endl;

    std::cout << std::endl;

    //////////////////////////////
    // Printing literal strings //
    //////////////////////////////

    // A 'string' is a 'sequence or
    // string of zero or more
    // characters'. A sting is
    // preceded by an opening
    // doublequote (") and ended with
    // a closing doublequote.
    // Most characters on the
    // keyboard can appear in a
    // string with the exception of
    // the doublequote and the
    // backslash.

    std::cout
        << "I am afraid I can't do that"
        << " Dave." << std::endl;

    // If the string is too long for
    // the output console (the
    // screen), the text simply wraps
    // to the next line.
    std::cout
        << "Look Dave, I can see"
        << " you're really upset about"
        << " this. I honestly think"
        << " you ought to sit down"
        << " calmly, take a stress"
        << " pill, and think things"
        << " over." << std::endl;

    // In order to include a " or \
  // in a string, you must
    // prefix that character by a
    // backslash.

    std::cout
        << "A quote ',"
        << " a doublequote \" and"
        << " a backslash \\"
        << std::endl;

    std::cout
        << "My home directory is "
        << "\"C:\\Users\\Douglas\\\""
        << std::endl;

    std::cout << std::endl;

    ////////////////////////////
    // Printing literal       //
    // floating-point numbers //
    ////////////////////////////

    std::cout
        << "For floats, by default,"
        << " only six digits are"
        << " printed."
        << std::endl;
    std::cout
        << "pi = "
        << 3.141592654
        << std::endl;

    std::cout
        << "c = "
        << 299792.458
        << " km/s" << std::endl;

    std::cout
        << "123456.7 = " << 123456.7
        << std::endl;

    std::cout << "1/3 = "
              << 0.33333333333 << std::endl;

    std::cout << "2/3 = "
              << 0.55555555555 << std::endl;

    std::cout << 1.0 << std::endl;

    std::cout << 0.001234567
              << std::endl;

    std::cout
        << "Both large and small"
        << " numbers are printed in"
        << " scientific notation"
        << std::endl;
    std::cout
        << "c = "
        << 1079252848.8
        << " km/h" << std::endl;

    std::cout
        << "h = "
        << 0.000000000000000000000000000000000662607004
        << " kg m^2/s" << std::endl;

    std::cout << std::endl;

    //////////////////////
    // Printing literal //
    //  Boolean values  //
    //////////////////////

    std::cout << "True:  "
              << true << std::endl;
    std::cout << "False: "
              << false << std::endl;

    return 0;
}

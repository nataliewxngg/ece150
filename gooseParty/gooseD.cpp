#include <iostream>
// avoid using \f - linefeed character
int main() {
  std::cout << "     p<\r\f";
  std::cout << "\"___/\r\f";
  std::cout << " \\=/\r\f";
  std::cout << "  \\_\r\f";
  return 0;
}
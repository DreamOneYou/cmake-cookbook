#include "Message.hpp"

#include <cstdlib>
#include <iostream>



int main() {
  // Message say_hello("Hello, CMake World!");

  // std::cout << say_hello << std::endl;

  // Message say_goodbye("Goodbye, CMake World");

  // std::cout << say_goodbye << std::endl;

  int a = 10,b=12;
  std::cout<<"before="<<"a="<<a<<"b="<<b<<std::endl;
  swap(a,b);
  std::cout<<"after="<<"a="<<a<<"b="<<b<<std::endl;
  system("pause");
  return EXIT_SUCCESS;
}

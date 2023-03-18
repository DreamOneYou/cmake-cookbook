#include "Message.hpp"

#include <iostream>
#include <string>

void swap(int &a, int &b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}

std::ostream &Message::printObject(std::ostream &os) {
  os << "This is my very nice message: " << std::endl;
  os << message_;

  return os;
}

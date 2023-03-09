//
// Created by Hanbin Kim on 3/3/23.
//

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "please enter only 2 argument\n";
    return 1  ;
  }
  std::cout.precision(std::numeric_limits<double>::digits10);
  ScalarConverter::convert(argv[1]);
}
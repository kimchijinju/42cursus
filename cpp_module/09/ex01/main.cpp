//
// Created by Hanbin Kim on 4/22/23.
//

#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Error\n";
    return 1;
  }
  std::string input(argv[1]);
  calculator(input);
}
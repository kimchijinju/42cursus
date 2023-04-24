//
// Created by Hanbin Kim on 4/24/23.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "PmergeMe.hpp"

bool isNumber(const std::string &str);

int main(int argc, char *argv[])
{
  std::stringstream printBuffer;
  std::vector<int> vector;

  for (int i = 1; i < argc; ++i)
  {
    if (!isNumber(argv[i]))
    {
      std::cerr << "Error\n";
      return 1;
    }
    vector.push_back(std::atoi(argv[i]));
  }
  printBuffer << "Before: ";
  for (size_t i = 0; i < vector.size(); ++i)
  {
    printBuffer << vector[i] << " ";
  }

  time_t beforeTime = time(NULL);
  std::sort(vector.begin(), vector.end());
  time_t afterTime = time(NULL);

  printBuffer << "\nAfter:  ";
  for (size_t i = 0; i < vector.size(); ++i)
  {
    printBuffer << vector[i] << " ";
  }
  printBuffer << "\nTime to process a range of "
              << vector.size()
              << " elements with std::[..] : "
              << afterTime - beforeTime
              << "us";
  std::cout << printBuffer.str() << '\n';
}

bool isNumber(const std::string &str)
{
  for (size_t i = 0; i < str.length(); ++i)
  {
    if (!isdigit(str[i]))
      return false;
  }
  return true;
}

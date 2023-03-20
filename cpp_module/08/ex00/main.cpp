//
// Created by Hanbin Kim on 3/18/23.
//

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
  std::vector<int> vector;
  for (int i = 0; i < 10; ++i)
  {
    vector.push_back(i);
  }
  std::cout << (easyfind(vector, -1) ? "Find" : "Does not exist") << '\n';
  std::cout << (easyfind(vector, 5) ? "Find" : "Does not exist") << '\n';
  std::cout << (easyfind(vector, 11) ? "Find" : "Does not exist") << '\n';


}
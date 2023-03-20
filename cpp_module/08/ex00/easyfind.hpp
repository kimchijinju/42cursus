//
// Created by Hanbin Kim on 3/18/23.
//

#ifndef INC_08_EX00_EASYFIND_HPP_
#define INC_08_EX00_EASYFIND_HPP_

#include <algorithm>
#include <iterator>

template<typename Container>
bool easyfind(Container &c, int target)
{
  return *std::find(c.begin(), c.end(), target) == target;
}

#endif //INC_08_EX00_EASYFIND_HPP_

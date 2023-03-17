//
// Created by Hanbin Kim on 3/15/23.
//

#ifndef INC_07_EX01_ITER_HPP_
#define INC_07_EX01_ITER_HPP_

#include <cstdlib>

template<typename T>
void iter(T *begin, size_t length, void (*f)(T&)) {
  for (size_t i = 0; i < length; ++i) {
    f(begin[i]);
  }
}

#endif //INC_07_EX01_ITER_HPP_

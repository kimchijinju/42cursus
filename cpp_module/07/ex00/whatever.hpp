//
// Created by Hanbin Kim on 3/10/23.
//

#ifndef INC_07_EX00_WHATEVER_HPP_
#define INC_07_EX00_WHATEVER_HPP_


template<typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template<typename T>
T& min(T &a, T &b) {
  if (a == b)
    return b;
  return a < b ? a : b;
}

template<typename T>
T& max(T &a, T &b) {
  if (a == b)
    return b;
  return a > b ? a : b;
}
#endif //INC_07_EX00_WHATEVER_HPP_

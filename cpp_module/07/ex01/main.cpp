//
// Created by Hanbin Kim on 3/15/23.
//

#include <iostream>
#include "iter.hpp"

void myPrint(int n) {
  std::cout << n << '\n';
}

int main() {
  size_t ptr_length = 10;
  int *ptr = new int[ptr_length];
  for (size_t i = 0; i < ptr_length; ++i) {
    ptr[i] = i;
  }
  iter(ptr, ptr_length, myPrint);
}
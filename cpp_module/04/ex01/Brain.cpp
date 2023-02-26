//
// Created by Hanbin Kim on 2/26/23.
//

#include <iostream>
#include "Brain.hpp"

Brain::Brain() : ideas() {
  std::cout << "Call Brain constructor.\n";
}

Brain::~Brain() {
  std::cout << "Call Brain destructor.\n";
}

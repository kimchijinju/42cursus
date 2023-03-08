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

Brain::Brain(const Brain &brain) {
  for (int i = 0; i < 100; ++i)
    ideas[i] = brain.ideas[i];
}

Brain &Brain::operator=(const Brain &brain) {
  if (this == &brain)
    return *this;

  for (int i = 0; i < 100; ++i)
    ideas[i] = brain.ideas[i];
  return *this;
}

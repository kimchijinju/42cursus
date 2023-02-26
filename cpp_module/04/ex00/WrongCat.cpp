//
// Created by Hanbin Kim on 2/23/23.
//

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "Call WrongCat constructor.\n";
}

WrongCat::~WrongCat() {
  std::cout << "Call WrongCat destructor.\n";
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat.type) {
  std::cout << "Call WrongCat copy constructor.\n";
}

WrongCat &WrongCat::operator=(const WrongCat &cat) {
  std::cout << "Call WrongCat copy assignment.\n";
  if (this == &cat)
    return *this;

  type = cat.type;
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "Wrong meow....\n";
}

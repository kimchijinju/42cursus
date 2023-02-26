#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Call Cat constructor.\n";
}

Cat::~Cat() {
  std::cout << "Call Cat destructor.\n";
}

Cat::Cat(const Cat &cat) : Animal(cat.type) {
  std::cout << "Call Cat copy constructor.\n";
}

Cat &Cat::operator=(const Cat &cat) {
  std::cout << "Call Cat copy assignment.\n";
  if (this == &cat)
    return *this;

  type = cat.type;
  return *this;
}

void Cat::makeSound() const {
  std::cout << "meow....\n";
}

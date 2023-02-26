#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
  std::cout << "Call Cat constructor.\n";
}

Cat::~Cat() {
  std::cout << "Call Cat destructor.\n";
  delete brain;
}

Cat::Cat(const Cat &cat) : Animal(cat.type), brain(new Brain()) {
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

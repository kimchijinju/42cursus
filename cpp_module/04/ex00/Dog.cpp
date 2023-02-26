#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Call Dog constructor.\n";

}

Dog::~Dog() {
  std::cout << "Call Dog destructor.\n";

}

Dog::Dog(const Dog &dog) : Animal(dog.type) {
  std::cout << "Call Dog copy constructor.\n";
}

Dog &Dog::operator=(const Dog &dog) {
  std::cout << "Call Dog copy assignment.\n";
  if (this == &dog)
    return *this;

  type = dog.type;
  return *this;
}

void Dog::makeSound() const {
  std::cout << "bark....\n";
}

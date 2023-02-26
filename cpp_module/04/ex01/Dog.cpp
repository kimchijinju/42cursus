#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
  std::cout << "Call Dog constructor.\n";

}

Dog::~Dog() {
  std::cout << "Call Dog destructor.\n";
  delete brain;
}

Dog::Dog(const Dog &dog) : Animal(dog.type), brain(new Brain()) {
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

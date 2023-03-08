#include <iostream>
#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), brain(new Brain()) {
  std::cout << "Call Dog constructor.\n";

}

Dog::~Dog() {
  std::cout << "Call Dog destructor.\n";
  delete brain;
}

Dog::Dog(const Dog &dog) : AAnimal(dog.type), brain(new Brain(*dog.brain)) {
  std::cout << "Call Dog copy constructor.\n";
}

Dog &Dog::operator=(const Dog &dog) {
  std::cout << "Call Dog copy assignment.\n";
  if (this == &dog)
    return *this;

  type = dog.type;
  *brain = *dog.brain;
  return *this;
}

void Dog::makeSound() const {
  std::cout << "bark....\n";
}

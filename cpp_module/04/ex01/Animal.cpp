//
// Created by Hanbin Kim on 2/23/23.
//

#include <iostream>
#include "Animal.hpp"

Animal::Animal() : type("") {
  std::cout << "Call animal constructor.\n";

}

Animal::Animal(const std::string &_type) : type(_type) {
  std::cout << "Call animal-type constructor.\n";
}

Animal::~Animal() {
  std::cout << "Call animal destructor.\n";
}

Animal::Animal(const Animal &animal) : type(animal.type) {
  std::cout << "Call animal copy constructor.\n";

}

Animal &Animal::operator=(const Animal &animal) {
  std::cout << "Call animal copy constructor.\n";
  if (this == &animal)
    return *this;

  type = animal.type;
  return *this;
}

void Animal::makeSound() const {
  std::cout << "Animal class can't cry.\n";
}

const std::string &Animal::getType() const {
  return type;
}
void Animal::setType(const std::string &_type) {
  type = _type;
}

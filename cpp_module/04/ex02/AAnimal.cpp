//
// Created by Hanbin Kim on 2/23/23.
//

#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal(const std::string &_type) : type(_type) {
  std::cout << "Call animal-type constructor.\n";
}

AAnimal::~AAnimal() {
  std::cout << "Call animal destructor.\n";
}

AAnimal::AAnimal(const AAnimal &animal) : type(animal.type) {
  std::cout << "Call animal copy constructor.\n";
}

AAnimal &AAnimal::operator=(const AAnimal &animal) {
  std::cout << "Call animal copy constructor.\n";
  if (this == &animal)
    return *this;

  type = animal.type;
  return *this;
}

const std::string &AAnimal::getType() const {
  return type;
}
void AAnimal::setType(const std::string &_type) {
  type = _type;
}

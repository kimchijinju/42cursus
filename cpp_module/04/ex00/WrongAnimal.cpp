#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") {
  std::cout << "Call WrongAnimal constructor.\n";

}

WrongAnimal::WrongAnimal(const std::string &_type) : type(_type) {
  std::cout << "Call WrongAnimal-type constructor.\n";
}

WrongAnimal::~WrongAnimal() {
  std::cout << "Call WrongAnimal destructor.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) : type(animal.type) {
  std::cout << "Call WrongAnimal copy constructor.\n";

}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
  std::cout << "Call WrongAnimal copy assignment.\n";
  if (this == &animal)
    return *this;

  type = animal.type;
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal class can't cry.\n";
}

const std::string &WrongAnimal::getType() const {
  return type;
}
void WrongAnimal::setType(const std::string &_type) {
  type = _type;
}
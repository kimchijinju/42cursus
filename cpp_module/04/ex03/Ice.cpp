//
// Created by Hanbin Kim on 2/27/23.
//

#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

AMateria *Ice::clone() const {
  return new Ice();
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

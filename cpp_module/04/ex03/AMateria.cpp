//
// Created by Hanbin Kim on 2/27/23.
//

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(const std::string &type) : type_(type) {}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
  return type_;
}

void AMateria::use(ICharacter &target) {
  std::cout << target.getName() << "\n";
}

//
// Created by Hanbin Kim on 2/27/23.
//

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : type_(type) {}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
  return type_;
}

void AMateria::use(ICharacter &target) {
  target.getName();
}

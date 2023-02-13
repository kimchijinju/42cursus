//
// Created by 김한빈 on 2023/02/13.
//

#include "Weapon.h"

Weapon::Weapon(std::string _type) : type(_type) {}

const std::string &Weapon::getType() const {
  return type;
}

void Weapon::setType(std::string _type) {
  type = _type;
}

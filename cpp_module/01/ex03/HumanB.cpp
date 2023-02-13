//
// Created by 김한빈 on 2023/02/13.
//

#include <iostream>
#include "HumanB.h"

HumanB::HumanB(std::string _name) : weapon(NULL), name(_name) {}

void HumanB::setWeapon(Weapon &_weapon) {
  weapon = &_weapon;
}

void HumanB::attack() {
  if (weapon == NULL) {
    std::cout << name << " hasn't weapon\n";
    return;
  }
  std::cout << name << " attacks with their " << weapon->getType() << '\n';
}
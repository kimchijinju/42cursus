//
// Created by 김한빈 on 2023/02/13.
//

#include <iostream>
#include "HumanA.h"

HumanA::HumanA(std::string _name, Weapon &_weapon) :
    weapon(_weapon), name(_name) {}

void HumanA::attack() {
  std::cout << name << " attacks with their " << weapon.getType() << '\n';
}
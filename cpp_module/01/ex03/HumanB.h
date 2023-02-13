//
// Created by 김한빈 on 2023/02/13.
//

#ifndef CPP_MODULE_01_EX03_HUMANB_H_
#define CPP_MODULE_01_EX03_HUMANB_H_

#include "Weapon.h"

class HumanB {
 public:
  HumanB(std::string _name);
  void setWeapon(Weapon &_weapon);
  void attack();

 private:
  Weapon *weapon;
  std::string name;
};

#endif //CPP_MODULE_01_EX03_HUMANB_H_

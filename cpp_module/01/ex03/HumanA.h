//
// Created by 김한빈 on 2023/02/13.
//

#ifndef CPP_MODULE_01_EX03_HUMANA_H_
#define CPP_MODULE_01_EX03_HUMANA_H_

#include <string>
#include "Weapon.h"

class HumanA {
 public:
  HumanA(std::string _name, Weapon& _weapon);
  void attack();

 private:
  Weapon &weapon;
  std::string name;
};

#endif //CPP_MODULE_01_EX03_HUMANA_H_

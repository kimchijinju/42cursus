//
// Created by 김한빈 on 2023/02/13.
//

#ifndef CPP_MODULE_01_EX03_WEAPON_HPP_
#define CPP_MODULE_01_EX03_WEAPON_HPP_

#include <string>

class Weapon {
 public:
  Weapon(std::string _type);
  const std::string &getType() const;
  void setType(std::string _type);

 private:
  std::string type;
};

#endif //CPP_MODULE_01_EX03_WEAPON_HPP_

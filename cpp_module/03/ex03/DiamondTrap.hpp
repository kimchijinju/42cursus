//
// Created by Hanbin Kim on 2/23/23.
//

#ifndef INC_03_EX03_DIAMONDTRAP_HPP_
#define INC_03_EX03_DIAMONDTRAP_HPP_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, FragTrap {
 public:
  DiamondTrap();
  DiamondTrap(const std::string &_name);
  ~DiamondTrap();
  DiamondTrap(const DiamondTrap &diamondTrap);
  DiamondTrap &operator= (const DiamondTrap &diamondTrap);
  void whoAmI();

 private :
  std::string name;
};

#endif //INC_03_EX03_DIAMONDTRAP_HPP_

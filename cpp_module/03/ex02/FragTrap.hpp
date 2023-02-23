//
// Created by Hanbin Kim on 2/23/23.
//

#ifndef INC_03_EX02_FRAGTRAP_HPP_
#define INC_03_EX02_FRAGTRAP_HPP_

#include "ClapTrap.hpp"
class FragTrap : public ClapTrap {
 public:
  FragTrap();
  FragTrap(const std::string &name);
  ~FragTrap();
  FragTrap(const FragTrap &fragTrap);
  FragTrap &operator=(const FragTrap &fragTrap);

  void highFivesGuys(void);
};

#endif //INC_03_EX02_FRAGTRAP_HPP_

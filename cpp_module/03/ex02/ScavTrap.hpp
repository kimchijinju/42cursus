#ifndef INC_03_EX01_SCAVTRAP_HPP_
#define INC_03_EX01_SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap();
  ScavTrap(const std::string &name);
  ~ScavTrap();
  ScavTrap(const ScavTrap &scavTrap);
  ScavTrap &operator= (const ScavTrap &scavTrap);

  virtual void attack(const std::string &target);
  void guardGate();
};

#endif //INC_03_EX01_SCAVTRAP_HPP_

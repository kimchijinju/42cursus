//
// Created by Hanbin Kim on 2/21/23.
//

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default", 100, 50, 20) {

  std::cout << "ScavTrap " << name << " is create from default constructor.\n";
}

ScavTrap::ScavTrap(const std::string &_name) : ClapTrap(_name, 100, 50, 20) {
  std::cout << "ScavTrap " << name << " is create from constructor.\n";
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << name << " is delete.\n";
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap.name,
                                                        scavTrap.hitPoint,
                                                        scavTrap.energyPoint,
                                                        scavTrap.attackDamage) {
  std::cout << "ScavTrap " << name << " is copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
  std::cout << "ScavTrap " << name << " is copy assignment operator called\n";

  if (this == &scavTrap)
    return *this;

  name = scavTrap.name;
  hitPoint = scavTrap.hitPoint;
  energyPoint = scavTrap.energyPoint;
  attackDamage = scavTrap.attackDamage;

  return *this;
}

void ScavTrap::attack(const std::string &target) {
  if (isEnergyPointEmpty() || isHitPointZero())
    return;

  std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!\n";
  --energyPoint;
  std::cout << "ScavTrap " << name << " energy point is " << energyPoint << ".\n";
}

void ScavTrap::guardGate() {
  if (isHitPointZero())
    return;
  std::cout << "ScavTrap " << name << " now gate keeper mode.\n";
}

#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("defalut_clap_name", 100, 50, 30), name("default") {
  std::cout << "DiamondTrap " << name << " is create from default constructor.\n";
}

DiamondTrap::DiamondTrap(const std::string &_name) : ClapTrap(_name + "_clap_name", 100, 50, 30), name(_name) {
  std::cout << "DiamondTrap " << name << " is create from constructor.\n";
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << name << " is delete.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(diamondTrap.ClapTrap::name,
                                                                    diamondTrap.hitPoint,
                                                                    diamondTrap.energyPoint,
                                                                    diamondTrap.attackDamage), name(diamondTrap.name) {
  std::cout << "DiamondTrap " << name << " is copy constructor called\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
  std::cout << "DiamondTrap " << name << " is copy assignment operator called\n";

  if (this == &diamondTrap)
    return *this;

  name = diamondTrap.name;
  ClapTrap::name = diamondTrap.ClapTrap::name;
  hitPoint = diamondTrap.hitPoint;
  energyPoint = diamondTrap.energyPoint;
  attackDamage = diamondTrap.attackDamage;

  return *this;
}

void DiamondTrap::whoAmI() {
  std::cout << "Who am i? i'am " << name << ", " << ClapTrap::name << ". \n";

}

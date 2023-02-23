#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("defalut", 100, 100, 30) {
  std::cout << "FragTrap " << name << " is create from default constructor.\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30) {
  std::cout << "FragTrap " << name << " is create from constructor.\n";
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << name << " is delete.\n";
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap.name,
                                                        fragTrap.hitPoint,
                                                        fragTrap.energyPoint,
                                                        fragTrap.attackDamage) {
  std::cout << "FragTrap " << name << " is copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
  std::cout << "FragTrap " << name << " is copy assignment operator called\n";

  if (this == &fragTrap)
    return *this;

  name = fragTrap.name;
  hitPoint = fragTrap.hitPoint;
  energyPoint = fragTrap.energyPoint;
  attackDamage = fragTrap.attackDamage;

  return *this;
}

void FragTrap::highFivesGuys(void) {
  if (isHitPointZero())
    return;

  std::cout << "FragTrap " << name << " do highfive!!!\n";
}

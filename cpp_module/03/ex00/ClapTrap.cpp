#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoint(10), energyPoint(10), attackDamage(0) {
  std::cout << "ClapTrap " << name << " is create from default constructor.\n";
}

ClapTrap::ClapTrap(const std::string& _name) : name(_name), hitPoint(10), energyPoint(10), attackDamage(0) {
  std::cout << "ClapTrap " << name << " is create from name constructor.\n";
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name << " is delete.\n";
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
    : name(clapTrap.name),
      hitPoint(clapTrap.hitPoint),
      energyPoint(clapTrap.energyPoint),
      attackDamage(clapTrap.attackDamage) {
  std::cout << "ClapTrap " << name << " is create from copy constructor.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
  std::cout << "ClapTrap " << name << " is copy assignment operator called\n";

  if (this == &clapTrap)
    return *this;

  name = clapTrap.name;
  hitPoint = clapTrap.hitPoint;
  energyPoint = clapTrap.energyPoint;
  attackDamage = clapTrap.attackDamage;

  return *this;
}
void ClapTrap::attack(const std::string &target) {
  if (isEnergyPointEmpty())
    return;

  std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!\n";
  --energyPoint;
  std::cout << "ClapTrap " << name << " energy point is " << energyPoint << ".\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (isHitPointZero())
    return;


  std::cout << "ClapTrap " << name << " is take " << amount << " damage.\n";
  if (hitPoint < amount)
    amount = hitPoint;
  hitPoint -= amount;
  std::cout << "ClapTrap " << name << " hit point is " << hitPoint << ".\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (isEnergyPointEmpty())
    return;

  std::cout << "ClapTrap " << name << " is " << amount << " repair.\n";
  if (hitPoint > UINT_MAX - amount)
    hitPoint = UINT_MAX;
  else
    hitPoint += amount;
  --energyPoint;

  std::cout << "ClapTrap " << name << " hit point is " << hitPoint << ".\n";
  std::cout << "ClapTrap " << name << " energy point is " << energyPoint << ".\n";
}

bool ClapTrap::isEnergyPointEmpty() {
  if (energyPoint == 0) {
    std::cout << "ClapTrap " << name << " is used up all energy point\n";
    return true;
  }
  return false;
}

bool ClapTrap::isHitPointZero() {
  if (hitPoint == 0) {
    std::cout << "ClapTrap " << name << " is hit point zero.\n";
    return true;
  }
  return false;
}

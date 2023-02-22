#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoint(10), energyPoint(10), attackDamage(0) {
  std::cout << "ClapTrap " << name << " is create from default constructor.\n";
}

ClapTrap::ClapTrap(const std::string &_name) : name(_name), hitPoint(10), energyPoint(10), attackDamage(0) {
  std::cout << "ClapTrap " << name << " is create from constructor.\n";
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

ClapTrap::ClapTrap(const std::string &name,
                   unsigned int hit_point,
                   unsigned int energy_point,
                   unsigned int attack_damage)
    : name(name), hitPoint(hit_point), energyPoint(energy_point), attackDamage(attack_damage) {
  std::cout << "ClapTrap " << name << " is create from constructor.\n";
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
  if (isEnergyPointEmpty() || isHitPointZero())
    return;

  std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!\n";
  --energyPoint;
  printEnergyPointStatus();
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (isHitPointZero())
    return;

  std::cout << "ClapTrap " << name << " is take " << amount << " damage.\n";
  if (hitPoint < amount)
    amount = hitPoint;
  hitPoint -= amount;
  printHitPointStatus();
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (isEnergyPointEmpty() || isHitPointZero())
    return;

  std::cout << "ClapTrap " << name << " is " << amount << " repair.\n";
  if (hitPoint > UINT_MAX - amount)
    hitPoint = UINT_MAX;
  else
    hitPoint += amount;
  --energyPoint;

  printHitPointStatus();
  printEnergyPointStatus();
}

void ClapTrap::printHitPointStatus() {
  std::cout << "ClapTrap " << name << " hit point is " << hitPoint << ".\n";
}

void ClapTrap::printEnergyPointStatus() {
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

const std::string &ClapTrap::getName() const {
  return name;
}
unsigned int ClapTrap::getAttackDamage() const {
  return attackDamage;
}

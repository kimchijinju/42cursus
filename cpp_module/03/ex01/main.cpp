#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ScavTrap hanbkim("hanbkim");
  std::cout << '\n';
  ClapTrap jaeyyoo("jaeyyoo");
  std::cout << '\n';

  jaeyyoo.attack(hanbkim.getName());
  std::cout << '\n';
  hanbkim.takeDamage(jaeyyoo.getAttackDamage());
  std::cout << '\n';
  hanbkim.attack(jaeyyoo.getName());
  std::cout << '\n';
  jaeyyoo.takeDamage(hanbkim.getAttackDamage());
  std::cout << '\n';
  hanbkim.beRepaired(5);
  std::cout << '\n';
  jaeyyoo.attack(hanbkim.getName());
  std::cout << '\n';
  jaeyyoo.beRepaired(5);
  std::cout << '\n';
  hanbkim.guardGate();
}
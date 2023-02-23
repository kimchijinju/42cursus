#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
  ScavTrap hanbkim("hanbkim");
  std::cout << '\n';
  ClapTrap jaeyyoo("jaeyyoo");
  std::cout << '\n';
  FragTrap jiyunpar("jiyunpar");
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
  std::cout << '\n';

  jiyunpar.highFivesGuys();
  std::cout << '\n';

  jiyunpar.attack(hanbkim.getName());
  std::cout << '\n';
  hanbkim.takeDamage(jiyunpar.getAttackDamage());
  std::cout << '\n';

  hanbkim.attack(jiyunpar.getName());
  std::cout << '\n';
  jiyunpar.takeDamage(hanbkim.getAttackDamage());
  std::cout << '\n';

  for (int i = 0; i < 3; ++i) {
    jiyunpar.attack(hanbkim.getName());
    std::cout << '\n';
    hanbkim.takeDamage(jiyunpar.getAttackDamage());
    std::cout << '\n';
  }
  hanbkim.guardGate();
}
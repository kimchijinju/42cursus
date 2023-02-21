#include "ClapTrap.hpp"
#include <iostream>

int main() {
  ClapTrap hanbkim("hanbkim");
  std::cout << '\n';

  hanbkim.attack("jaeyyoo");
  std::cout << '\n';
  hanbkim.beRepaired(5);
  std::cout << '\n';
  hanbkim.takeDamage(5);
  std::cout << '\n';

  hanbkim.takeDamage(61);
  std::cout << '\n';
}
#include <iostream>
#include "DiamondTrap.hpp"

int main() {
  DiamondTrap hanbkim("hanbkim");
  std::cout << '\n';
  ClapTrap dummy("dummy");
  std::cout << '\n';

  hanbkim.attack(dummy.getName());
  std::cout << '\n';
  hanbkim.whoAmI();
  std::cout << '\n';
}
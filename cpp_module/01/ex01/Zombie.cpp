#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
  std::cout << "zombie allocated..\n";
}

Zombie::~Zombie() {
  std::cout << name << " is delete..\n";
}

void Zombie::announce() {
  std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string _name) {
  name = _name;
}
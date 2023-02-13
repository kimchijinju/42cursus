#include <iostream>
#include "Zombie.hpp"

Zombie::~Zombie() {
  std::cout << name << " is delete..\n";
}

void Zombie::announce() {
  std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string _name) : name(_name) {}


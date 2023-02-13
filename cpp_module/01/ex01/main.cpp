#include "Zombie.hpp"

int main() {
  int zombieCount = 5;
  Zombie *zombie = zombieHorde(zombieCount, "zombie");

  for (int i = 0; i < zombieCount; ++i) {
    zombie[i].announce();
  }
  delete []zombie;
}
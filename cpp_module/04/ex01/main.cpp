#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  Animal *animal[4];

  for (int i = 0; i < 4; ++i) {
    if (i == 0 || i == 1)
      animal[i] = new Cat();
    else
      animal[i] = new Dog();
  }

  for (int i = 0; i < 4; ++i) {
    animal[i]->makeSound();
  }

  (*animal)[0] = (*animal)[3]; // deep copy
  std::cout << "0 : " << animal[0]->getType() << "\n1 : " << animal[3]->getType() << '\n';

  for (int i = 0; i < 4; ++i) {
    animal[i]->makeSound();
  }

  for (int i = 0; i < 4; ++i) {
    delete animal[i];
  }
  return 0;
}
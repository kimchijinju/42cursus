#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  AAnimal *animal[4];

  for (int i = 0; i < 4; ++i) {
    if (i == 0 || i == 1)
      animal[i] = new Cat();
    else
      animal[i] = new Dog();
  }

  for (int i = 0; i < 4; ++i) {
    animal[i]->makeSound();
  }

  for (int i = 0; i < 4; ++i) {
    delete animal[i];
  }
  return 0;
}
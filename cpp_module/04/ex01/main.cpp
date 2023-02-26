#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  Animal *dog = new Dog[3];
  Animal *cat = new Cat[3];

  dog[0].getType();
  cat[0].getType();
  system("leaks Brain");
  return 0;
}
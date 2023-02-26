#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

int main() {
  const Animal *meta = new Animal();
  const Animal *dog = new Dog();
  const Animal *cat = new Cat();
  std::cout << dog->getType() << " " << std::endl;
  std::cout << cat->getType() << " " << std::endl;

  cat->makeSound(); //will output the cat sound!
  dog->makeSound();
  meta->makeSound();

  std::cout << '\n';

  const WrongAnimal *wrongMeta = new WrongAnimal();
  const WrongAnimal *wrongCat = new WrongCat();

  std::cout << wrongCat->getType() << " " << std::endl;
  wrongMeta->makeSound();
  wrongCat->makeSound();

  delete meta;
  delete dog;
  delete cat;
  delete wrongMeta;
  delete wrongCat;
  return 0;
}
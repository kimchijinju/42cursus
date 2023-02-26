#ifndef INC_04_EX00_DOG_HPP_
#define INC_04_EX00_DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog();
  virtual ~Dog();
  Dog(const Dog &dog);
  Dog &operator=(const Dog &dog);

  virtual void makeSound() const;
};

#endif //INC_04_EX00_DOG_HPP_

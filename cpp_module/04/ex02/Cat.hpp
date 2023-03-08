#ifndef INC_04_EX00_CAT_HPP_
#define INC_04_EX00_CAT_HPP_

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
 public:
  Cat();
  virtual ~Cat();
  Cat(const Cat &cat);
  Cat &operator=(const Cat &cat);

  virtual void makeSound() const;

 private:
  Brain *brain;
};

#endif //INC_04_EX00_CAT_HPP_

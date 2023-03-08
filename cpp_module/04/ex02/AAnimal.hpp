//
// Created by Hanbin Kim on 2/23/23.
//

#ifndef INC_04_EX00_ANIMAL_HPP_
#define INC_04_EX00_ANIMAL_HPP_

#include <string>

class AAnimal {
 public:
  AAnimal(const AAnimal &animal);
  AAnimal &operator=(const AAnimal &animal);
  AAnimal(const std::string &_type);
  virtual ~AAnimal();

  void setType(const std::string &_type);
  const std::string &getType() const;
  virtual void makeSound() const = 0;

 protected:
  std::string type;

 private:
  AAnimal();
};

#endif //INC_04_EX00_ANIMAL_HPP_

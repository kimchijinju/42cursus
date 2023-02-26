//
// Created by Hanbin Kim on 2/23/23.
//

#ifndef INC_04_EX00_ANIMAL_HPP_
#define INC_04_EX00_ANIMAL_HPP_

#include <string>

class Animal {
 public:
  Animal();
  Animal(const std::string &_type);
  virtual ~Animal();
  Animal(const Animal &animal);
  Animal &operator=(const Animal &animal);

  void setType(const std::string &_type);
  const std::string &getType() const;
  virtual void makeSound() const;

 protected:
  std::string type;

};

#endif //INC_04_EX00_ANIMAL_HPP_

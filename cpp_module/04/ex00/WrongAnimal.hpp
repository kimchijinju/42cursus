//
// Created by Hanbin Kim on 2/23/23.
//

#ifndef INC_04_EX00_WRONGANIMAL_HPP_
#define INC_04_EX00_WRONGANIMAL_HPP_

#include <string>

class WrongAnimal {
 public:
  WrongAnimal();
  WrongAnimal(const std::string &_type);
  virtual ~WrongAnimal();
  WrongAnimal(const WrongAnimal &animal);
  WrongAnimal &operator=(const WrongAnimal &animal);

  void setType(const std::string &_type);
  const std::string &getType() const;
  void makeSound() const;

 protected:
  std::string type;
};

#endif //INC_04_EX00_WRONGANIMAL_HPP_

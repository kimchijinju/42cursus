//
// Created by Hanbin Kim on 2/23/23.
//

#ifndef INC_04_EX00_WRONGCAT_HPP_
#define INC_04_EX00_WRONGCAT_HPP_

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  virtual ~WrongCat();
  WrongCat(const WrongCat &wcat);
  WrongCat &operator=(const WrongCat &cat);

  void makeSound() const;
};

#endif //INC_04_EX00_WRONGCAT_HPP_

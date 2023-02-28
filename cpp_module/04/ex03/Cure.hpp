//
// Created by Hanbin Kim on 2/27/23.
//

#ifndef INC_04_EX03_CURE_HPP_
#define INC_04_EX03_CURE_HPP_

#include "AMateria.hpp"

class Cure : public AMateria {
 public :
  Cure();
  virtual ~Cure();

  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);

 private:
  Cure(const Cure &cure);
  Cure &operator=(const Cure &cure);
};

#endif //INC_04_EX03_CURE_HPP_

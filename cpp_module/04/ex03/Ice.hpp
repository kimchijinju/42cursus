//
// Created by Hanbin Kim on 2/27/23.
//

#ifndef INC_04_EX03_ICE_HPP_
#define INC_04_EX03_ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria {
 public :
  Ice();
  virtual ~Ice();

  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);

 private:
  Ice(const Ice &ice);
  Ice &operator=(const Ice &ice);

};

#endif //INC_04_EX03_ICE_HPP_

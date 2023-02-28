//
// Created by Hanbin Kim on 2/27/23.
//

#ifndef INC_04_EX03_CHARACTER_HPP_
#define INC_04_EX03_CHARACTER_HPP_

#include <string>
#include <list>
#include "ICharacter.hpp"

class Character : public ICharacter {
 public:
  Character(std::string const &name);
  ~Character();
  Character(const Character &character);
  Character &operator=(const Character &character);

  virtual const std::string &getName() const;
  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);

 private:
  std::string name_;
  AMateria *slot_[4];
  static const int max_slot_ = 4;

  std::list<AMateria *> inventory;

 private: // not use
  Character();
};

#endif //INC_04_EX03_CHARACTER_HPP_

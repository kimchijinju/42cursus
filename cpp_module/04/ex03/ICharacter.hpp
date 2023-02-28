#ifndef INC_04_EX03_ICHARACTER_HPP_
#define INC_04_EX03_ICHARACTER_HPP_

#include <string>

class AMateria;

class ICharacter {
 public:
  virtual ~ICharacter() {}
  virtual std::string const &getName() const = 0;
  virtual void equip(AMateria *m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter &target) = 0;
};

#endif //INC_04_EX03_ICHARACTER_HPP_

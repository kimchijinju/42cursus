#ifndef INC_04_EX03_AMATERIA_HPP_
#define INC_04_EX03_AMATERIA_HPP_

#include <string>
#include "ICharacter.hpp"

class AMateria {
 public:
  AMateria(std::string const &type);
  virtual ~AMateria();

  std::string const &getType() const;

  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);

 protected:
  std::string type_;

 private:
  AMateria();
  AMateria(const AMateria &aMateria);
  AMateria &operator=(const AMateria &aMateria);
};

#endif //INC_04_EX03_AMATERIA_HPP_

//
// Created by Hanbin Kim on 2/27/23.
//

#ifndef INC_04_EX03_IMATERIASOURCE_HPP_
#define INC_04_EX03_IMATERIASOURCE_HPP_

#include <string>

class AMateria;

class IMateriaSource {
 public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria *) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif //INC_04_EX03_IMATERIASOURCE_HPP_

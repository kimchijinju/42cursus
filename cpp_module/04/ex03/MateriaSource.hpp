//
// Created by Hanbin Kim on 2/27/23.
//

#ifndef INC_04_EX03_MATERIASOURCE_HPP_
#define INC_04_EX03_MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource();
  ~MateriaSource();
  MateriaSource(const MateriaSource &materiaSource);
  MateriaSource &operator=(const MateriaSource &materiaSource);

  virtual void learnMateria(AMateria *materia);
  virtual AMateria *createMateria(const std::string &type);

 private:
  AMateria *memorize_[4];
  static const int MAX_MEMORIZE = 4;
};

#endif //INC_04_EX03_MATERIASOURCE_HPP_

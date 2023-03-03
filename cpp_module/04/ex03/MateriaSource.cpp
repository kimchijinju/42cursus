//
// Created by Hanbin Kim on 2/27/23.
//

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() : memorize_() {

}

MateriaSource::~MateriaSource() {

}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
  for (int i = 0; i < MAX_MEMORIZE; ++i) {
    memorize_[i] = materiaSource.memorize_[i]->clone();
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
  if (this == &materiaSource)
    return *this;
  for (int i = 0; i < MAX_MEMORIZE; ++i) {
    if (memorize_[i] != NULL) {
      delete memorize_[i];
      memorize_[i] = NULL;
    }
    if (materiaSource.memorize_[i] != NULL) {
      memorize_[i] = materiaSource.memorize_[i]->clone();
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
  for (int i = 0; i < MAX_MEMORIZE; ++i) {
    if (memorize_[i] == NULL) {
      memorize_[i] = materia;
      return;
    }
  }
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i = 0; i < MAX_MEMORIZE; ++i) {
    if (memorize_[i] == NULL) {
      continue;
    }
    if (memorize_[i]->getType() == type) {
      return memorize_[i]->clone();
    }
  }
  return NULL;
}

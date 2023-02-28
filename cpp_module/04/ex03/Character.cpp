//
// Created by Hanbin Kim on 2/27/23.
//

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string &name) : name_(name), slot_(), inventory() {}

Character::Character(const Character &character) : name_(character.name_), inventory(character.inventory) {
  for (int i = 0; i < max_slot_; ++i) {
    if (character.slot_[i] != NULL)
      slot_[i] = character.slot_[i]->clone();
  }
}

Character &Character::operator=(const Character &character) {
  if (this == &character)
    return *this;

  for (int i = 0; i < max_slot_; ++i) {
    if (slot_[i] != NULL) {
      delete slot_[i];
      slot_[i] = NULL;
    }
    if (character.slot_[i] != NULL) {
      slot_[i] = character.slot_[i]->clone();
    }
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < max_slot_; ++i) {
    if (slot_[i] != NULL)
      delete slot_[i];
  }
}

const std::string &Character::getName() const {
  return name_;
}

void Character::equip(AMateria *m) {
  for (int i = 0; i < max_slot_; ++i) {
    if (slot_[i] != NULL) {
      slot_[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= max_slot_)
    return;
  inventory.push_back(slot_[idx]);
  slot_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= max_slot_)
    return;
  slot_[idx]->AMateria::use(target);
}

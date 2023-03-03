//
// Created by Hanbin Kim on 2/27/23.
//

#include "Character.hpp"
#include "AMateria.hpp"
#include "Inventory.hpp"

Character::Character(const std::string &name) : name_(name), slot_(), inventory_() {}

Character::Character(const Character &character) : name_(character.name_), inventory_(character.inventory_) {
  for (int i = 0; i < MAX_SLOT; ++i) {
    if (character.slot_[i] != NULL)
      slot_[i] = character.slot_[i]->clone();
  }
}

Character &Character::operator=(const Character &character) {
  if (this == &character)
    return *this;

  for (int i = 0; i < MAX_SLOT; ++i) {
    if (slot_[i] != NULL) {
      delete slot_[i];
      slot_[i] = NULL;
    }
    if (character.slot_[i] != NULL) {
      slot_[i] = character.slot_[i]->clone();
    }
  }
  inventory_ = character.inventory_;
  return *this;
}

Character::~Character() {
  for (int i = 0; i < MAX_SLOT; ++i) {
    if (slot_[i] != NULL)
      delete slot_[i];
  }
}

const std::string &Character::getName() const {
  return name_;
}

void Character::equip(AMateria *m) {
  for (int i = 0; i < MAX_SLOT; ++i) {
    if (slot_[i] == NULL) {
      slot_[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= MAX_SLOT)
    return;
  if (slot_[idx] == NULL)
    return;
  if (!inventory_.keep(slot_[idx])) {
    inventory_.drop();
    inventory_.keep((slot_[idx]));
  }
  slot_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= MAX_SLOT)
    return;
  if (slot_[idx] == NULL)
    return;
  slot_[idx]->use(target);
}

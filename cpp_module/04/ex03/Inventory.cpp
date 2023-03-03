//
// Created by Hanbin Kim on 3/3/23.
//

#include <iostream>
#include "Inventory.hpp"
#include "AMateria.hpp"

Inventory::Inventory() : slot_(), slotSize_(0) {
  for (int i = 0; i < 1000; ++i)
    slot_[i] = NULL;
}

Inventory::~Inventory() {}

Inventory::Inventory(const Inventory &inventory) : slot_(), slotSize_(inventory.slotSize_) {
  for (int i = 0; i < slotSize_; ++i) {
    if (inventory.slot_[i] != NULL)
      slot_[i] = inventory.slot_[i]->clone();
  }
}

Inventory &Inventory::operator=(const Inventory &inventory) {
  if (this == &inventory)
    return *this;

  for (int i = 0; i < MAX_SLOT; ++i) {
    if (slot_[i] != NULL) {
      delete slot_[i];
      slot_[i] = NULL;
    }
    if (inventory.slot_[i] != NULL) {
      slot_[i] = inventory.slot_[i]->clone();
    }
  }
  return *this;
}

bool Inventory::keep(AMateria *materia) {
  if (slotSize_ >= MAX_SLOT) {
    std::cout << "inventory is full.\n";
    return false;
  }
  slot_[slotIndex_] = materia;
  ++slotIndex_;
  ++slotSize_;
  return true;
}

void Inventory::drop() {
  delete slot_[slotIndex_];
  slot_[slotIndex_] = NULL;
  --slotIndex_;
}

void Inventory::drop(int idx) {
  if (idx >= MAX_SLOT)
    return;
  if (slot_[idx] == NULL)
    return;
  delete slot_[idx];
}

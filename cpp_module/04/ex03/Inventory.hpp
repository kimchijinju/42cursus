//
// Created by Hanbin Kim on 3/3/23.
//

#ifndef EX03__INVENTORY_HPP_
#define EX03__INVENTORY_HPP_

class AMateria;

class Inventory {
 public:
  Inventory();
  ~Inventory();
  Inventory(const Inventory &inventory);
  Inventory &operator= (const Inventory &inventory);

  bool keep(AMateria *materia);
  void drop();
  void drop(int idx);

 private:
  AMateria *slot_[1000];
  const static unsigned int MAX_SLOT = 1000;
  unsigned int slotIndex_;
  unsigned int slotSize_;
};

#endif //EX03__INVENTORY_HPP_

//
// Created by Hanbin Kim on 3/9/23.
//

#include "Serialize.hpp"

uintptr_t Serialize::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serialize::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}

//
// Created by Hanbin Kim on 3/9/23.
//

#ifndef INC_06_EX01_SERIALIZE_HPP_
#define INC_06_EX01_SERIALIZE_HPP_

#include <cstdint>

struct Data;

class Serialize {
 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

 private: // not use
  Serialize();
  ~Serialize();
  Serialize(const Serialize &serialize);
  Serialize &operator= (const Serialize &serialize);
};

#endif //INC_06_EX01_SERIALIZE_HPP_

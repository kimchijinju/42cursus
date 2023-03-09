#include <iostream>
#include "Serialize.hpp"

struct Data {
  int value;
};

int main() {
  Data *data = new Data();
  data->value = 10;

  uintptr_t address = Serialize::serialize(data);
  std::cout << "data pointer value : " << data << '\n';
  std::cout << "serialize value : " << address << '\n';

  Data *deserializeData = Serialize::deserialize(address);
  std::cout << (data == deserializeData ? "equals" : "not equals") << '\n';
}
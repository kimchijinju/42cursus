#ifndef INC_01_ZOMBIE_H
#define INC_01_ZOMBIE_H

#include <string>

class Zombie {

 public:
  Zombie();
  ~Zombie();
  void announce(void);
  void setName(std::string _name);

 private:
  std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif //INC_01_ZOMBIE_H

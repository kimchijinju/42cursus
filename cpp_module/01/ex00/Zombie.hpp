#ifndef INC_01_ZOMBIE_H
#define INC_01_ZOMBIE_H

#include <string>

class Zombie {

 public:
  Zombie(std::string name);
  ~Zombie();
  void announce(void);

 private:
  std::string name;
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif //INC_01_ZOMBIE_H

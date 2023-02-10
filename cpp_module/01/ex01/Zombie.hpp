#ifndef INC_01_ZOMBIE_H
#define INC_01_ZOMBIE_H

#include <string>

class Zombie {

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce (void);

private:
    std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif //INC_01_ZOMBIE_H

#ifndef INC_03_EX00_CLAPTRAP_HPP_
#define INC_03_EX00_CLAPTRAP_HPP_

#include <string>

class ClapTrap {
 public:
  ClapTrap();
  ClapTrap(const std::string& _name);
  ~ClapTrap();
  ClapTrap(const ClapTrap &clapTrap);
  ClapTrap &operator= (const ClapTrap &clapTrap);

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 private:
  bool isEnergyPointEmpty();
  bool isHitPointZero();

  std::string name;
  unsigned int hitPoint;
  unsigned int energyPoint;
  unsigned int attackDamage;
};

#endif //INC_03_EX00_CLAPTRAP_HPP_

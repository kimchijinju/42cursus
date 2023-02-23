#ifndef INC_03_EX00_CLAPTRAP_HPP_
#define INC_03_EX00_CLAPTRAP_HPP_

#include <string>

class ClapTrap {
 public:
  ClapTrap();
  ClapTrap(const std::string &name, unsigned int hit_point, unsigned int energy_point, unsigned int attack_damage);
  ClapTrap(const std::string &_name);
   ~ClapTrap();
  ClapTrap(const ClapTrap &clapTrap);
  ClapTrap &operator=(const ClapTrap &clapTrap);

  virtual void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  const std::string &getName() const;
  unsigned int getAttackDamage() const;

 protected:
  void printHitPointStatus();
  void printEnergyPointStatus();
  bool isEnergyPointEmpty();
  bool isHitPointZero();

  std::string name;
  unsigned int hitPoint;
  unsigned int energyPoint;
  unsigned int attackDamage;
};

#endif //INC_03_EX00_CLAPTRAP_HPP_

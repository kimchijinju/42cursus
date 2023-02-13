#include "Zombie.hpp"

int main() {
  Zombie *hanbkim = newZombie("hanbkim");
  hanbkim->announce();
  delete hanbkim;

  randomChump("joushin");

//    Zombie *wbae = newZombie("wbae");
//    wbae->announce();
}
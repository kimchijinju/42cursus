#include <iostream>
#include "Harl.h"

Harl::Harl() {
  f[0] = &Harl::debug;
  f[1] = &Harl::info;
  f[2] = &Harl::warning;
  f[3] = &Harl::error;
  messageLevel[0] = "DEBUG";
  messageLevel[1] = "INFO";
  messageLevel[2] = "WARNING";
  messageLevel[3] = "ERROR";
}
void Harl::complain(std::string level) {
  int level_index = -1;

  for (int i = 0; i < 4; ++i) {
    if (level == messageLevel[i])
      level_index = i;
  }

  switch (level_index) {
    case 0 : debug();
    case 1 : info();
    case 2 : warning();
    case 3 : error();
      break;
    default : invalid();
  }
}

void Harl::debug() {
  std::cout << "[ DEBUG ]\n"
            << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\n\n";
}

void Harl::info() {
  std::cout << "[ INFO ]\n"
            << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning() {
  std::cout << "[ WARNING ]\n"
            << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error() {
  std::cout << "[ ERROR ]\n"
            << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::invalid() {
  std::cout << "[ Probably complaining about insignificant problems ]\n";
}
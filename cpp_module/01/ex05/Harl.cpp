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
  for (int i = 0; i < 4; ++i) {
    if (level == messageLevel[i])
      (this->*f[i])();
  }
}

void Harl::debug() {
  std::cout
      << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\n";
}

void Harl::info() {
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning() {
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error() {
  std::cout
      << "This is unacceptable! I want to speak to the manager now.\n";
}
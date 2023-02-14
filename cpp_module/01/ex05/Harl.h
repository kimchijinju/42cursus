#ifndef CPP_MODULE_01_EX05_HARL_H_
#define CPP_MODULE_01_EX05_HARL_H_

#include <string>

class Harl {
 public:
  Harl();
  void complain(std::string level);

 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  void (Harl::*f[4]) (void);
  std::string messageLevel[4];
};

#endif //CPP_MODULE_01_EX05_HARL_H_

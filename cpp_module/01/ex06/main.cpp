#include "Harl.h"

int main(int argc, char **argv) {
  if (argc != 2)
    return 1;

  Harl harl;
  harl.complain(argv[1]);
}

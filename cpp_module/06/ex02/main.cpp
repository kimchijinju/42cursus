#include "Base.hpp"

int main() {
  Base base;
  Base *gen = base.generate();
  base.identify(gen);
  base.identify(*gen);

}
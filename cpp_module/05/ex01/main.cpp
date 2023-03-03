#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Bureaucrat staff("Staff", 120);
    Bureaucrat assistantManager("Assistant Manager", 90);
    std::cout << staff << '\n';
    std::cout << assistantManager << '\n';

    Form form("business report", 100, 50);

    staff.signForm(form);
    std::cout << "signed? : " << (form.getSigned() ? "YES" : "NO") << '\n';
    assistantManager.signForm(form);
    std::cout << "signed? : " << (form.getSigned() ? "YES" : "NO") << '\n';

  } catch (std::exception &e) {
    std::cout << e.what();
  }

}

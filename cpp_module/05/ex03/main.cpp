#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

using std::cout;

void doWork(Bureaucrat *hanbkim, Bureaucrat *jaeyyoo, AForm *hello) {
  try {
    hanbkim->executeForm(*hello);
    cout << '\n';
    hanbkim->signForm(*hello);
    cout << '\n';

    jaeyyoo->executeForm(*hello);
    cout << '\n';

  } catch (std::exception &e) {
    cout << e.what() << '\n';
  }
  delete hanbkim;
  delete jaeyyoo;
  delete hello;
}

int main() {
  Intern intern;
  cout << "====================ShrubberyCreationForm=========================\n";
  doWork(new Bureaucrat("hanbkim", 140),
         new Bureaucrat("jaeyyoo", 130),
         intern.makeForm("shrubbery creation", "hello"));
  cout << "====================ShrubberyCreationForm=========================\n";
  cout << "\n";
  cout << "\n";

  cout << "=====================RobotomyRequestForm=========================\n";
  doWork(new Bureaucrat("hanbkim", 60),
         new Bureaucrat("jaeyyoo", 40),
         intern.makeForm("robotomy request", "hello"));
  cout << "=====================RobotomyRequestForm=========================\n";
  cout << "\n";
  cout << "\n";

  cout << "=====================PresidentialPardonForm=========================\n";
  doWork(new Bureaucrat("hanbkim", 25),
         new Bureaucrat("jaeyyoo", 3),
         intern.makeForm("presidential pardon", "hello"));
  cout << "=====================PresidentialPardonForm=========================\n";

  cout << "\n";
  cout << "\n";
  intern.makeForm("ahahsdf", "hello");
}

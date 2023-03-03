#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

  cout << "====================ShrubberyCreationForm=========================\n";
  doWork(new Bureaucrat("hanbkim", 140),
         new Bureaucrat("jaeyyoo", 130),
         new ShrubberyCreationForm("hello"));
  cout << "====================ShrubberyCreationForm=========================\n";
  cout << "\n";
  cout << "\n";

  cout << "=====================RobotomyRequestForm=========================\n";
  doWork(new Bureaucrat("hanbkim", 60),
         new Bureaucrat("jaeyyoo", 40),
         new RobotomyRequestForm("hello"));
  cout << "=====================RobotomyRequestForm=========================\n";
  cout << "\n";
  cout << "\n";

  cout << "=====================PresidentialPardonForm=========================\n";
  doWork(new Bureaucrat("hanbkim", 25),
         new Bureaucrat("jaeyyoo", 3),
         new PresidentialPardonForm("hello"));
  cout << "=====================PresidentialPardonForm=========================\n";
}

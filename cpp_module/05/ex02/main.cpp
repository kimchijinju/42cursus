#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::cout;

void doWork(Bureaucrat &hanbkim, Bureaucrat &jaeyyoo, AForm &hello) {
  try {
    hanbkim.executeForm(hello);
    cout << '\n';
    hanbkim.signForm(hello);
    cout << '\n';

    jaeyyoo.executeForm(hello);
    cout << '\n';

  } catch (std::exception &e) {
    cout << e.what() << '\n';
  }
}

int main() {
  Bureaucrat *hanbkim, *jaeyyoo;
  AForm *hello;

  hanbkim = new Bureaucrat("hanbkim",140);
  jaeyyoo = new Bureaucrat("jaeyyoo", 130);
  hello = new ShrubberyCreationForm("hello");
  cout << "====================ShrubberyCreationForm=========================\n";
  doWork(*hanbkim, *jaeyyoo, *hello);
  delete hanbkim;
  delete jaeyyoo;
  delete hello;
  cout << "====================ShrubberyCreationForm=========================\n";
  cout << "\n";
  cout << "\n";


  cout << "=====================RobotomyRequestForm=========================\n";
  hanbkim = new Bureaucrat("hanbkim",60);
  jaeyyoo = new Bureaucrat("jaeyyoo", 40);
  hello = new RobotomyRequestForm("hello");
  doWork(*hanbkim, *jaeyyoo, *hello);
  delete hanbkim;
  delete jaeyyoo;
  delete hello;
  cout << "=====================RobotomyRequestForm=========================\n";
  cout << "\n";
  cout << "\n";

  cout << "=====================PresidentialPardonForm=========================\n";
  hanbkim = new Bureaucrat("hanbkim",25);
  jaeyyoo = new Bureaucrat("jaeyyoo", 3);
  hello = new PresidentialPardonForm("hello");
  doWork(*hanbkim, *jaeyyoo, *hello);
  delete hanbkim;
  delete jaeyyoo;
  delete hello;
  cout << "=====================PresidentialPardonForm=========================\n";
}

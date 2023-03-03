//
// Created by Hanbin Kim on 3/3/23.
//

#ifndef EX03__INTERN_HPP_
#define EX03__INTERN_HPP_

#include <string>

class AForm;

class Intern {

 public:
  Intern();
  ~Intern();
  AForm *makeForm(std::string const &formName, std::string const &formTarget);

 private:
  const static unsigned int MAX_MEMORIZE = 3;
  AForm *(Intern::*makeFormFunction[MAX_MEMORIZE])(std::string const &);

  AForm *makeShrubberyCreationForm(std::string const &target);
  AForm *makeRobotomyRequestForm(std::string const &target);
  AForm *makePresidentialPardonForm(std::string const &target);


  std::string memorizeForm[MAX_MEMORIZE];

 private: // not use
  Intern(const Intern &intern);
  Intern &operator=(const Intern &intern);
};

#endif //EX03__INTERN_HPP_

//
// Created by Hanbin Kim on 3/1/23.
//

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name,
           const unsigned int signable_grade,
           const unsigned int executable_grade)
    : name_(name), signed_(false), signable_grade_(signable_grade), executable_grade_(executable_grade) {
  if (signable_grade_ < 1 || executable_grade_ < 1)
    throw GradeTooHighException();
  if (signable_grade_ > 150 || executable_grade_ > 150)
    throw GradeTooLowException();
}

Form::~Form() {

}

Form::Form(const Form &form)
    : name_(form.name_),
      signed_(form.signed_),
      signable_grade_(form.signable_grade_),
      executable_grade_(form.executable_grade_) {

}

void Form::beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException) {
  if (signable_grade_ < bureaucrat.getGrade())
    throw GradeTooLowException();
  signed_ = true;
}

const std::string &Form::getName() const {
  return name_;
}

bool Form::getSigned() const {
  return signed_;
}

unsigned int Form::getSignableGrade() const {
  return signable_grade_;
}

unsigned int Form::getExecutableGrade() const {
  return executable_grade_;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Form: grade too high.";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Form: grade too low.";
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
  out << "name : " << form.getName()
      << "\nsigned : " << form.getSigned()
      << "\nsignable_grade : " << form.getSignableGrade()
      << "\nexecutable_grade : " << form.getExecutableGrade() << '\n';
  return out;
}

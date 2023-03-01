//
// Created by Hanbin Kim on 2/28/23.
//

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : name_(name), grade_(grade) {
  if (grade_ < 1)
    throw GradeTooHighException();
  if (grade_ > 150)
    throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name_(bureaucrat.name_), grade_(bureaucrat.grade_) {

}

const std::string &Bureaucrat::getName() const {
  return name_;
}

unsigned int Bureaucrat::getGrade() const {
  return grade_;
}

void Bureaucrat::increaseGrade() throw(GradeTooHighException) {
  if (grade_ <= 1)
    throw GradeTooHighException();
  --grade_;
}

void Bureaucrat::decreaseGrade() throw(GradeTooLowException) {
  if (grade_ >= 150)
    throw GradeTooLowException();
  ++grade_;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Bureaucrat grade too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Bureaucrat grade too low.";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
  return out;
}

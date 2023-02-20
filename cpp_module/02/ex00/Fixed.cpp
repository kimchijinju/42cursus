#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
  std::cout << "Default constructor called\n";
}

Fixed::~Fixed() {
  std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called\n";
  value = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called\n";

  if (this == &fixed)
    return *this;

  value = fixed.value;
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called\n";
  return value;
}

void Fixed::setRawBits(int const raw) {
  value = raw;
}
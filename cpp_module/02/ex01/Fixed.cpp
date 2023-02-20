#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << "Default constructor called\n";
  value = 0;
}

Fixed::Fixed(const int n) : value(n << factionalBits) {
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float n) : value(roundf(n * 256.0f)) {
  std::cout << "Float constructor called\n";
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

float Fixed::toFloat() const {
  return (float) value / 256.0f;
}

int Fixed::toInt() const {
  return value >> 8;
}

int Fixed::getRawBits(void) const {
  return value;
}

void Fixed::setRawBits(int const raw) {
  value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}
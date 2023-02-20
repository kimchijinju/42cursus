#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << "Default constructor called\n";
  value = 0;
}

Fixed::Fixed(const int n) {
  std::cout << "Int constructor called\n";
  value = n << factionalBits;
}

Fixed::Fixed(const float n) {
  std::cout << "Float constructor called\n";
  value = roundf(n * 256.0f);
}

Fixed::~Fixed() {
  std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called\n";
  value = fixed.value;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called\n";

  if (this == &fixed)
    return *this;

  value = fixed.getRawBits();
  return *this;
}

bool Fixed::operator>(const Fixed &fixed) const {
  return value > fixed.value;
}
bool Fixed::operator<(const Fixed &fixed) const {
  return value < fixed.value;
}
bool Fixed::operator>=(const Fixed &fixed) const {
  return value >= fixed.value;
}
bool Fixed::operator<=(const Fixed &fixed) const {
  return value <= fixed.value;
}
bool Fixed::operator==(const Fixed &fixed) const {
  return value == fixed.value;
}
bool Fixed::operator!=(const Fixed &fixed) const {
  return value != fixed.value;
}

Fixed Fixed::operator+(const Fixed &fixed) {
  return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) {
  return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
  return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) {
  return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++() {
  ++value;
  return *this;
}

const Fixed Fixed::operator++(int) {
  const Fixed temp = (*this);
  ++value;
  return temp;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
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

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
  return f1 > f2 ? f1 : f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
  return f1 > f2 ? f1 : f2;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
  return f1 < f2 ? f1 : f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
  return f1 < f2 ? f1 : f2;
}

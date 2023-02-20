#ifndef CPP_MODULE_FIXED_HPP
#define CPP_MODULE_FIXED_HPP

class Fixed {

 public:
  Fixed();
  Fixed(const int n);
  Fixed(const float n);
  ~Fixed();
  Fixed(const Fixed &fixed);

  Fixed &operator=(const Fixed &fixed);

  bool operator>(const Fixed &fixed) const;
  bool operator<(const Fixed &fixed) const;
  bool operator>=(const Fixed &fixed) const;
  bool operator<=(const Fixed &fixed) const;
  bool operator==(const Fixed &fixed) const;
  bool operator!=(const Fixed &fixed) const;

  Fixed operator+(const Fixed &fixed);
  Fixed operator-(const Fixed &fixed);
  Fixed operator*(const Fixed &fixed) const;
  Fixed operator/(const Fixed &fixed);

  Fixed &operator++();
  const Fixed operator++(int);

  static Fixed &max(Fixed &f1, Fixed &f2);
  static const Fixed &max(const Fixed &f1, const Fixed &f2);
  static Fixed &min(Fixed &f1, Fixed &f2);
  static const Fixed &min(const Fixed &f1, const Fixed &f2);

  float toFloat(void) const;
  int toInt(void) const;
  int getRawBits(void) const;
  void setRawBits(int const raw);

 private:
  int value;
  static const int factionalBits = 8;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif //CPP_MODULE_FIXED_HPP

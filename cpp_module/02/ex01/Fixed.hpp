//
// Created by Hanbin Kim on 2/15/23.
//

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

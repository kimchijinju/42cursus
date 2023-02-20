#ifndef CPP_MODULE_02_EX00_FIXED_HPP_
#define CPP_MODULE_02_EX00_FIXED_HPP_

class Fixed {

 public:
  Fixed();
  ~Fixed();
  Fixed(const Fixed &fixed);
  Fixed &operator=(const Fixed &fixed);

  int getRawBits(void) const;
  void setRawBits(int const raw);

 private:
  const static int bits = 8;
  int value;
};

#endif //CPP_MODULE_02_EX00_FIXED_HPP_

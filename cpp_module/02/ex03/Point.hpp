#ifndef INC_02_EX03_POINT_HPP_
#define INC_02_EX03_POINT_HPP_

#include "Fixed.hpp"

class Point {
 public:
  Point();
  Point(const float _x, const float _y);
  ~Point();
  Point(const Point &point);
  Point &operator= (const Point &point);

 private:
  const Fixed x;
  const Fixed y;
};

#endif //INC_02_EX03_POINT_HPP_

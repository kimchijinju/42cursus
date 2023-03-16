//
// Created by Hanbin Kim on 2/20/23.
//

#include "Point.hpp"

Point::Point() : x(Fixed()), y(Fixed()) {}

Point::Point(const float _x, const float _y) : x(Fixed(_x)), y(Fixed(_y)) {}

Point::~Point() {

}

Point::Point(const Point &point) : x(point.x), y(point.y) {}

Point &Point::operator=(const Point &point) {
  return *this;
}

//
// Created by tomas on 1. 2. 2023.
//

#include "Color.h"
#include "Equal.h"

TJRayTracer::Color::Color() : red(0.0), green(0.0), blue(0.0) {}
TJRayTracer::Color::Color(double red, double green, double blue)
    : red(red), green(green), blue(blue) {}
TJRayTracer::Color::~Color() noexcept {}

namespace TJRayTracer {
Color operator+(const Color &lhs, const Color &rhs) {
  Color result;
  if (&lhs != nullptr && &rhs != nullptr) {
    result.red = lhs.red + rhs.red;
    result.green = lhs.green + rhs.green;
    result.blue = lhs.blue + rhs.blue;
  }
  return result;
}

Color operator-(const Color &lhs, const Color &rhs) {
  Color result;
  if (&lhs != nullptr && &rhs != nullptr) {
    result.red = lhs.red - rhs.red;
    result.green = lhs.green - rhs.green;
    result.blue = lhs.blue - rhs.blue;
  }
  return result;
}

bool operator==(const Color &lhs, const Color &rhs) {
  if (&lhs != nullptr && &rhs != nullptr) {
    if (equal(lhs.red, rhs.red) && equal(lhs.green, rhs.green) &&
        equal(lhs.blue, rhs.blue)) {
      return true;
    }
  }
  return false;
}

Color Color::operator*(const double &scalar) const {
  Color result;
  if (this != nullptr) {
    result.red = this->red * scalar;
    result.green = this->green * scalar;
    result.blue = this->blue * scalar;
  }
  return result;
}

Color operator*(const Color &lhs, const Color &rhs) {
  Color result;
  if (&lhs != nullptr && &rhs != nullptr) {
    result.red = lhs.red * rhs.red;
    result.green = lhs.green * rhs.green;
    result.blue = lhs.blue * rhs.blue;
  }
  return result;
}

Color operator*(const double &scalar, const Color &rhs) {
  return (rhs * scalar);
}
} // namespace TJRayTracer

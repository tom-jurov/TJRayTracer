//
// Created by tomas on 28. 1. 2023.
//
#include "Vec4.h"
#include "Equal.h"

TJRayTracer::Vec4::Vec4() : x(0.0), y(0.0), z(0.0), w(0.0) {}

TJRayTracer::Vec4::Vec4(double x, double y, double z, double w)
    : x(x), y(y), z(z), w(w) {}

TJRayTracer::Vec4::Vec4(const Vec4 &other)
    : x(other.x), y(other.y), z(other.z), w(other.w) {}

TJRayTracer::Vec4::~Vec4() {}

bool TJRayTracer::Vec4::IsVector() const { return (equal(this->w, 0.0)); }

bool TJRayTracer::Vec4::IsPoint() const { return (equal(this->w, 1.0)); }

namespace TJRayTracer {
bool operator==(const Vec4 &lhs, const Vec4 &rhs) {
  if (&lhs != nullptr && &rhs != nullptr) {
    if (equal(lhs.x, rhs.x) && equal(lhs.y, rhs.y) && equal(lhs.z, rhs.z) &&
        equal(lhs.w, rhs.w)) {
      return true;
    }
  }
  return false;
}
} // namespace TJRayTracer

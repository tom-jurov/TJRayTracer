//
// Created by tomas on 29. 1. 2023.
//

#ifndef TJRAYTRACER_VECTOR_H
#define TJRAYTRACER_VECTOR_H
#include "Point.h"
#include "Vec4.h"

namespace TJRayTracer {
class Point;
class Vector : public Vec4 {
public:
  Vector();
  Vector(double x, double y, double z);
  ~Vector();

public:
  static double magnitude(const Vector &vector);
  static double dot(const Vector &lhs, const Vector &rhs);
  static Vector cross(const Vector &lhs, const Vector &rhs);
  static Vector reflect(const Vector &in, const Vector &normal);

public:
  friend Vector operator+(const Vector &lhs, const Vector &rhs);
  friend Vector operator-(const Vector &lhs, const Vector &rhs);
  friend Vector operator*(const double &scalar, const Vector &rhs);
  Vector operator*(const double &scalar) const;
  Vector operator/(const double &scalar) const;
  Vector operator-();
  Vector normalize() const;
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_VECTOR_H

//
// Created by tomas on 3. 2. 2023.
//

#ifndef TJRAYTRACER_TF_H
#define TJRAYTRACER_TF_H
#include <cmath>
#include "Utility.h"
namespace TJRayTracer {
class TF {
public:
  TF();
  static Matrix4d Identity();
  static Matrix4d translation(double x, double y, double z);
  static Matrix4d scaling(double x, double y, double z);
  static Matrix4d rotation_x(double angle);
  static Matrix4d rotation_y(double angle);
  static Matrix4d rotation_z(double angle);
  static Matrix4d shearing(double x_y, double x_z, double y_x,
                                         double y_z, double z_x, double z_y);
  [[nodiscard]] Matrix4d GetTransform() const;
  void operator=(const Matrix4d &other);
  ~TF() = default;

public:
  static Matrix4d
  view_transform(const Vector4d &from, const Vector4d &to, const Vector4d &up);

private:
  Matrix4d _transform;
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_TF_H

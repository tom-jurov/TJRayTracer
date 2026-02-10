//
// Created by tomas on 3. 2. 2023.
//

#ifndef TJRAYTRACER_RAY_H
#define TJRAYTRACER_RAY_H
#include "TJRayTracerGlobal.h"
#include "Utility.h"
namespace TJRayTracer {
class TJRAYTRACER_API Ray {
public:
  Ray();
  Ray(const Vector4d &origin, const Vector4d &direction);
  Ray(const Ray &) = default;
  Ray(Ray &&) = default;
  Ray &operator=(const Ray &) = default;
  Ray &operator=(Ray &&) = default;
  const Vector4d &GetOrigin() const;
  const Vector4d &GetDirection() const;
  void SetOrigin(const Vector4d &p);
  void SetDirection(const Vector4d &v);
  Vector4d position(double t) const;
  Ray transform(const Matrix4d &tf) const;
  ~Ray() = default;

private:
  Vector4d _origin;
  Vector4d _direction;
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_RAY_H

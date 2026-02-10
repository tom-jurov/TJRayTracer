//
// Created by tomas on 3. 2. 2023.
//

#ifndef TJRAYTRACER_SPHERE_H
#define TJRAYTRACER_SPHERE_H
#include "TJRayTracerGlobal.h"
#include "BaseObject.h"
#include "Ray.h"
#include <cmath>
namespace TJRayTracer {
class TJRAYTRACER_API Sphere : public BaseObject {
public:
  Sphere();
  Sphere(const Matrix4d &transform);
  ~Sphere();
  [[nodiscard]] std::vector<Intersection> local_intersect(const Ray &local_ray);
  [[nodiscard]] Vector4d local_normal_at(const Vector4d &local_point);
  static std::shared_ptr<Sphere> Glass_sphere();
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_SPHERE_H

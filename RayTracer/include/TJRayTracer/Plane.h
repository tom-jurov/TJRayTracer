//
// Created by tomas on 11. 2. 2023.
//

#ifndef TJRAYTRACER_PLANE_H
#define TJRAYTRACER_PLANE_H
#include "TJRayTracerGlobal.h"
#include "BaseObject.h"
#include "Equal.h"
#include "Ray.h"
#include <cmath>
namespace TJRayTracer {
class TJRAYTRACER_API Plane : public BaseObject {
public:
  Plane();
  Plane(const Matrix4d &transform);
  ~Plane();
  bool intersections(const Ray &ray);
  [[nodiscard]] std::vector<Intersection> local_intersect(const Ray &local_ray);
  [[nodiscard]] Vector4d local_normal_at(const Vector4d &local_point);
};
} // namespace TJRayTracer
#endif // TJRAYTRACER_PLANE_H

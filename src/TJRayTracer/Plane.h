//
// Created by tomas on 11. 2. 2023.
//

#ifndef TJRAYTRACER_PLANE_H
#define TJRAYTRACER_PLANE_H
#include "BaseObject.h"
#include "Equal.h"
#include "Ray.h"
#include "Vector.h"
#include <cmath>
namespace TJRayTracer {
class Plane : public BaseObject {
public:
  Plane();
  Plane(const MatrixXd<double, 4, 4> &transform);
  ~Plane();
  bool intersections(const Ray &ray);
  [[nodiscard]] std::vector<Intersection> local_intersect(const Ray &local_ray);
  [[nodiscard]] Vector local_normal_at(const Point &local_point);
};
} // namespace TJRayTracer
#endif // TJRAYTRACER_PLANE_H

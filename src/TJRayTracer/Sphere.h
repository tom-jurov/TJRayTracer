//
// Created by tomas on 3. 2. 2023.
//

#ifndef TJRAYTRACER_SPHERE_H
#define TJRAYTRACER_SPHERE_H
#include "BaseObject.h"
#include "Ray.h"
#include "Vector.h"
#include <cmath>
namespace TJRayTracer {
class Sphere : public BaseObject {
public:
  Sphere();
  Sphere(const MatrixXd<double, 4, 4> &transform);
  ~Sphere();
  [[nodiscard]] std::vector<Intersection> local_intersect(const Ray &local_ray);
  [[nodiscard]] Vector local_normal_at(const Point &local_point);
  static std::shared_ptr<Sphere> Glass_sphere();
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_SPHERE_H

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
  bool intersections(const Ray &ray);
  [[nodiscard]] std::vector<Intersection> intersect(const Ray &ray);
  [[nodiscard]] Vector normal_at(const Point &p);
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_SPHERE_H

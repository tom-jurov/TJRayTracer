#ifndef TJRAYTRACER_CYLINDER_H
#define TJRAYTRACER_CYLINDER_H
#include "BaseObject.h"
#include "Ray.h"
#include "Vector.h"
#include <cmath>
namespace TJRayTracer {
class Cylinder : public BaseObject {
public:
  Cylinder();
  Cylinder(const MatrixXd<double, 4, 4> &transform);
  ~Cylinder();
  [[nodiscard]] std::vector<Intersection> local_intersect(const Ray &local_ray);
  [[nodiscard]] Vector local_normal_at(const Point &local_point);
  static std::shared_ptr<Cylinder> Glass_cylinder();
};
} // namespace TJRayTracer

#endif
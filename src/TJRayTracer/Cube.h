#ifndef TJRAYTRACER_CUBE_H
#define TJRAYTRACER_CUBE_H
#include "BaseObject.h"

#include "BaseObject.h"
#include "Ray.h"
#include "Vector.h"
#include "Intersection.h"
#include <cmath>
namespace TJRayTracer {
class Cube : public BaseObject {
public:
  Cube();
  Cube(const MatrixXd<double, 4, 4> &transform);
  ~Cube();
  [[nodiscard]] std::vector<Intersection> local_intersect(const Ray &local_ray);
  [[nodiscard]] Vector local_normal_at(const Point &local_point);
  [[nodiscard]] std::vector<double> check_axis(double origin, double direction);
  static std::shared_ptr<Cube> Glass_cube();
};
} // namespace TJRayTracer
#endif
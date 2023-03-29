#ifndef TJRAYTRACER_CYLINDER_H
#define TJRAYTRACER_CYLINDER_H
#include "BaseObject.h"
#include "Ray.h"
#include <cmath>
namespace TJRayTracer {
class Cylinder : public BaseObject {
public:
  Cylinder();
  Cylinder(const Matrix4d &transform);
  ~Cylinder();
  [[nodiscard]] std::vector<Intersection> local_intersect(const Ray &local_ray);
  [[nodiscard]] Vector4d local_normal_at(const Vector4d &local_point);
  static std::shared_ptr<Cylinder> Glass_cylinder();
  void SetMaximum(double maximum);
  void SetMinimum(double minimum);
  double GetMaximum() const;
  double GetMinimum() const;
  bool IsClosed() const;
  void SetClosed(bool closed);
  bool check_cap(const Ray& ray, double t);
  void intersect_caps(const Ray &ray, std::vector<Intersection> & xs);

private:
    double _minimum;
    double _maximum;
    bool _closed;
};
} // namespace TJRayTracer

#endif
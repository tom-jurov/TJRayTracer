#ifndef TJRAYTRACER_CONES_H
#define TJRAYTRACER_CONES_H

#include "TJRayTracerGlobal.h"
#include "BaseObject.h"
#include "Ray.h"
#include <cmath>
namespace TJRayTracer {
class TJRAYTRACER_API Cones : public BaseObject {
public:
  Cones();
  Cones(const Matrix4d &transform);
  ~Cones();
  [[nodiscard]] std::vector<Intersection> local_intersect(const Ray &local_ray);
  [[nodiscard]] Vector4d local_normal_at(const Vector4d &local_point);
  static std::shared_ptr<Cones> Glass_cones();
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
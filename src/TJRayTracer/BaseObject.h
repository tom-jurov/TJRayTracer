//
// Created by tomas on 4. 2. 2023.
//

#ifndef TJRAYTRACER_BASEOBJECT_H
#define TJRAYTRACER_BASEOBJECT_H
#include "Intersection.h"
#include "Material.h"
#include "MatrixXd.h"
#include "Ray.h"
#include "TF.h"
#include "memory"
#include <vector>
namespace TJRayTracer {
class Material;
class Intersection;
class BaseObject {
public:
  BaseObject();
  BaseObject(const TJRayTracer::MatrixXd<double, 4, 4> &transform);
  virtual ~BaseObject();
  void SetTransform(const TJRayTracer::MatrixXd<double, 4, 4> &transform);
  TJRayTracer::MatrixXd<double, 4, 4> GetTransform() const;
  [[nodiscard]] virtual std::vector<Intersection>
  local_intersect(const Ray &local_ray) = 0;
  [[nodiscard]] std::vector<Intersection> intersect(const Ray &ray);
  [[nodiscard]] static Intersection
  hit(const std::vector<Intersection> &intersections);
  [[nodiscard]] virtual Vector
  local_normal_at(const TJRayTracer::Point &local_point) = 0;
  [[nodiscard]] Vector normal_at(const TJRayTracer::Point &point);

public:
  friend bool operator==(const TJRayTracer::BaseObject &lhs,
                         const TJRayTracer::BaseObject &rhs);

private:
  TJRayTracer::MatrixXd<double, 4, 4> _transform;

public:
  std::shared_ptr<Material> material = nullptr;
};
} // namespace TJRayTracer
#endif // TJRAYTRACER_BASEOBJECT_H

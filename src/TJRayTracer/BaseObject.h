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
#include <vector>
namespace TJRayTracer {
class Intersection;
class BaseObject {
public:
  BaseObject();
  BaseObject(const TJRayTracer::MatrixXd<double, 4, 4> &transform);
  virtual ~BaseObject();
  void SetTransform(const TJRayTracer::MatrixXd<double, 4, 4> &transform);
  TJRayTracer::MatrixXd<double, 4, 4> GetTransform() const;
  [[nodiscard]] virtual std::vector<Intersection> intersect(const Ray &ray);
  [[nodiscard]] static Intersection
  hit(const std::vector<Intersection> &intersections);
  [[nodiscard]] virtual Vector normal_at(const TJRayTracer::Point &p);

public:
  friend bool operator==(const TJRayTracer::BaseObject &lhs,
                         const TJRayTracer::BaseObject &rhs);

private:
  TJRayTracer::MatrixXd<double, 4, 4> _transform;

public:
  Material material;
};
} // namespace TJRayTracer
#endif // TJRAYTRACER_BASEOBJECT_H

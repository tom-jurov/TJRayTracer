//
// Created by tomas on 4. 2. 2023.
//

#ifndef TJRAYTRACER_BASEOBJECT_H
#define TJRAYTRACER_BASEOBJECT_H
#include "TJRayTracerGlobal.h"
#include "Intersection.h"
#include "Material.h"
#include "Ray.h"
#include "TF.h"
#include "memory"
#include <vector>
#include "Utility.h"
namespace TJRayTracer {
class Material;
class Intersection;
class TJRAYTRACER_API BaseObject {
public:
  BaseObject();
  BaseObject(const TJRayTracer::Matrix4d &transform);
  virtual ~BaseObject();
  void SetTransform(const TJRayTracer::Matrix4d &transform);
  TJRayTracer::Matrix4d GetTransform() const;
  [[nodiscard]] virtual std::vector<Intersection>
  local_intersect(const Ray &local_ray) = 0;
  [[nodiscard]] std::vector<Intersection> intersect(const Ray &ray);
  [[nodiscard]] static Intersection
  hit(const std::vector<Intersection> &intersections);
  [[nodiscard]] virtual Vector4d
  local_normal_at(const TJRayTracer::Vector4d &local_point) = 0;
  [[nodiscard]] Vector4d normal_at(const TJRayTracer::Vector4d &point);

public:
  friend bool operator==(const TJRayTracer::BaseObject &lhs,
                         const TJRayTracer::BaseObject &rhs);

private:
  TJRayTracer::Matrix4d _transform;

public:
  std::shared_ptr<Material> material = nullptr;
};
} // namespace TJRayTracer
#endif // TJRAYTRACER_BASEOBJECT_H

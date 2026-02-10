//
// Created by tomas on 11. 2. 2023.
//

#include "TJRayTracer/Plane.h"
TJRayTracer::Plane::Plane() : BaseObject() {}
TJRayTracer::Plane::Plane(const TJRayTracer::Matrix4d &transform)
    : BaseObject(transform) {}
TJRayTracer::Plane::~Plane() noexcept {}

std::vector<TJRayTracer::Intersection>
TJRayTracer::Plane::local_intersect(const Ray &local_ray) {
  std::vector<Intersection> intersections;
  if (fabs(local_ray.GetDirection().y()) < EPSILON) {
    return {};
  }
  double t = -local_ray.GetOrigin().y() / local_ray.GetDirection().y();
  intersections.emplace_back(
      std::move(Intersection(t, std::make_shared<Plane>(*this))));
  return intersections;
}

TJRayTracer::Vector4d
TJRayTracer::Plane::local_normal_at(const TJRayTracer::Vector4d &local_point) {
  return Vector4d(0, 1, 0, 0);
}

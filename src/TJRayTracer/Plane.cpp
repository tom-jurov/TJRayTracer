//
// Created by tomas on 11. 2. 2023.
//

#include "Plane.h"
TJRayTracer::Plane::Plane() : BaseObject() {}
TJRayTracer::Plane::Plane(const TJRayTracer::MatrixXd<double, 4, 4> &transform)
    : BaseObject(transform) {}
TJRayTracer::Plane::~Plane() noexcept {}

std::vector<TJRayTracer::Intersection>
TJRayTracer::Plane::local_intersect(const Ray &local_ray) {
  std::vector<Intersection> intersections;
  if (fabs(local_ray.GetDirection().y) < EPSILON) {
    return {};
  }
  double t = -local_ray.GetOrigin().y / local_ray.GetDirection().y;
  intersections.emplace_back(
      std::move(Intersection(t, std::make_shared<Plane>(*this))));
  return intersections;
}

TJRayTracer::Vector
TJRayTracer::Plane::local_normal_at(const TJRayTracer::Point &local_point) {
  return Vector(0, 1, 0);
}

//
// Created by tomas on 4. 2. 2023.
//

#include "TJRayTracer/BaseObject.h"
TJRayTracer::BaseObject::BaseObject()
    : _transform(TJRayTracer::TF::Identity()) {
  material = std::make_shared<Material>();
}
TJRayTracer::BaseObject::BaseObject(
    const TJRayTracer::Matrix4d &transform)
    : BaseObject() {
  _transform = transform;
}
TJRayTracer::BaseObject::~BaseObject() {}
std::vector<TJRayTracer::Intersection>
TJRayTracer::BaseObject::intersect(const TJRayTracer::Ray &ray) {
  Ray local_ray = std::move(ray.transform(_transform.inverse()));
  return local_intersect(local_ray);
}

TJRayTracer::Intersection TJRayTracer::BaseObject::hit(
    const std::vector<TJRayTracer::Intersection> &intersections) {
  std::vector<TJRayTracer::Intersection> positiveHits;
  for (auto &v : intersections) {
    if (v.t >= 0) {
      return v;
    }
  }
  return Intersection(-1, nullptr);
}

void TJRayTracer::BaseObject::SetTransform(
    const TJRayTracer::Matrix4d &transform) {
  _transform = transform;
}

TJRayTracer::Matrix4d
TJRayTracer::BaseObject::GetTransform() const {
  return _transform;
}

TJRayTracer::Vector4d
TJRayTracer::BaseObject::normal_at(const TJRayTracer::Vector4d &point) {
  Vector4d local_point = (_transform.inverse()) * point;
  Vector4d local_normal = std::move(this->local_normal_at(local_point));
  Matrix4d world_transform = this->GetTransform().inverse();
  world_transform.transposeInPlace();
  Vector4d world_normal = world_transform * local_normal;
  world_normal(3) = 0;
  return world_normal.normalized();
}

namespace TJRayTracer {
bool operator==(const BaseObject &lhs, const BaseObject &rhs) {
  if ((lhs.material == rhs.material) &&
      (lhs.GetTransform() == rhs.GetTransform())) {
    return true;
  }
  return false;
}

} // namespace TJRayTracer
//
// Created by tomas on 3. 2. 2023.
//

#include "TJRayTracer/Ray.h"

TJRayTracer::Ray::Ray()
    : _origin(Vector4d(0, 0, 0, 1)), _direction(Vector4d(0, 0, 0, 0)) {}
TJRayTracer::Ray::Ray(const Vector4d &origin, const Vector4d &direction)
    : _origin(origin), _direction(direction) {}

const TJRayTracer::Vector4d &TJRayTracer::Ray::GetOrigin() const {
  return _origin;
}
const TJRayTracer::Vector4d &TJRayTracer::Ray::GetDirection() const {
  return _direction;
}

TJRayTracer::Vector4d TJRayTracer::Ray::position(double t) const {
  return _origin + t * _direction;
}

TJRayTracer::Ray TJRayTracer::Ray::transform(
    const TJRayTracer::Matrix4d &tf) const {
  TJRayTracer::Ray result;
  result.SetOrigin(tf * this->GetOrigin());
  result.SetDirection(tf * this->GetDirection());
  return result;
}

void TJRayTracer::Ray::SetOrigin(const TJRayTracer::Vector4d &p) { _origin = p; }

void TJRayTracer::Ray::SetDirection(const TJRayTracer::Vector4d &v) {
  _direction = v;
}

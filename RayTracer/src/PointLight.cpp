//
// Created by tomas on 5. 2. 2023.
//

#include "TJRayTracer/PointLight.h"
#include <cmath>
TJRayTracer::PointLight::PointLight(const Vector4d &position,
                                    const Color &intensity)
    : _intensity(intensity), _position(position) {}
void TJRayTracer::PointLight::SetPosition(const Vector4d &position) {
  _position = position;
}
void TJRayTracer::PointLight::SetIntensity(const Color &intensity) {
  _intensity = intensity;
}

const TJRayTracer::Vector4d &TJRayTracer::PointLight::GetPosition() const {
  return _position;
}

const TJRayTracer::Color &TJRayTracer::PointLight::GetIntensity() const {
  return _intensity;
}

TJRayTracer::Color TJRayTracer::PointLight::lighting(
    const std::shared_ptr<Material> &m,
    const std::shared_ptr<BaseObject> &object,
    const TJRayTracer::PointLight &light, const TJRayTracer::Vector4d &position,
    const TJRayTracer::Vector4d &eyev, const TJRayTracer::Vector4d &normalv,
    bool in_shadow) {

  Color color;
  if (m->pattern) {
    color = m->pattern->pattern_at_object(object, position);
  } else {
    color = m->color;
  }
  Color effectiveColor = color * light.GetIntensity();
  Vector4d lightv = (light.GetPosition() - position).normalized();
  Color ambient = effectiveColor * m->ambient;
  if (in_shadow) {
    return ambient;
  }
  auto light_dot_normal = lightv.dot(normalv);
  Color diffuse;
  Color specular;
  Vector4d reflectv;
  double reflect_dot_eye = 0;
  if (light_dot_normal < 0) {
    diffuse = Color(0, 0, 0);
    specular = Color(0, 0, 0);
  } else {
    diffuse = effectiveColor * m->diffuse * light_dot_normal;
    reflectv = reflect(-lightv, normalv);
    reflect_dot_eye = reflectv.dot(eyev);
    if (reflect_dot_eye <= 0) {
      specular = Color(0, 0, 0);
    } else {
      double factor = pow(reflect_dot_eye, m->shininess);
      specular = light.GetIntensity() * m->specular * factor;
    }
  }
  return ambient + diffuse + specular;
}
namespace TJRayTracer {
bool operator==(const TJRayTracer::PointLight &lhs,
                const TJRayTracer::PointLight &rhs) {
  return (lhs.GetIntensity() == rhs.GetIntensity()) &&
         (lhs.GetPosition() == rhs.GetPosition());
}
} // namespace TJRayTracer

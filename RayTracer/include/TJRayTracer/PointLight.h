//
// Created by tomas on 5. 2. 2023.
//

#ifndef TJRAYTRACER_POINTLIGHT_H
#define TJRAYTRACER_POINTLIGHT_H
#include "TJRayTracerGlobal.h"
#include "Color.h"
#include "Material.h"
#include <memory>

namespace TJRayTracer {
class TJRAYTRACER_API PointLight {
public:
  PointLight() = default;
  PointLight(const Vector4d &position, const Color &intensity);
  const Color &GetIntensity() const;
  const Vector4d &GetPosition() const;
  void SetIntensity(const Color &intensity);
  void SetPosition(const Vector4d &position);
  ~PointLight() = default;
  PointLight(PointLight &&) = default;
  PointLight &operator=(PointLight &&) = default;
  PointLight(const PointLight &) = default;
  PointLight &operator=(const PointLight &) = default;

public:
  static Color lighting(const std::shared_ptr<Material> &m,
                        const std::shared_ptr<BaseObject> &object,
                        const PointLight &light, const Vector4d &position,
                        const Vector4d &eyev, const Vector4d &normalv,
                        bool in_shadow);
  friend bool operator==(const PointLight &lhs, const PointLight &rhs);

private:
  Color _intensity;
  Vector4d _position;
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_POINTLIGHT_H

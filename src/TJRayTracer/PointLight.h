//
// Created by tomas on 5. 2. 2023.
//

#ifndef TJRAYTRACER_POINTLIGHT_H
#define TJRAYTRACER_POINTLIGHT_H
#include "Color.h"
#include "Material.h"
#include "Point.h"
#include "Vector.h"
#include <memory>

namespace TJRayTracer {
class PointLight {
public:
  PointLight() = default;
  PointLight(const Point &position, const Color &intensity);
  const Color &GetIntensity() const;
  const Point &GetPosition() const;
  void SetIntensity(const Color &intensity);
  void SetPosition(const Point &position);
  ~PointLight() = default;
  PointLight(PointLight &&) = default;
  PointLight &operator=(PointLight &&) = default;
  PointLight(const PointLight &) = default;
  PointLight &operator=(const PointLight &) = default;

public:
  static Color lighting(const std::shared_ptr<Material> &m,
                        const std::shared_ptr<BaseObject> &object,
                        const PointLight &light, const Point &position,
                        const Vector &eyev, const Vector &normalv,
                        bool in_shadow);
  friend bool operator==(const PointLight &lhs, const PointLight &rhs);

private:
  Color _intensity;
  Point _position;
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_POINTLIGHT_H

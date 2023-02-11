//
// Created by tomas on 5. 2. 2023.
//

#ifndef TJRAYTRACER_MATERIAL_H
#define TJRAYTRACER_MATERIAL_H
#include "BasePattern.h"
#include "Color.h"
#include <memory>
namespace TJRayTracer {
class BasePattern;
class Material {
public:
  Material();
  Material(const Color &color, double ambient, double diffuse, double specular,
           double shininess, const std::shared_ptr<BasePattern> pattern);
  ~Material() = default;
  Material(Material &&) = default;
  Material &operator=(Material &&) = default;
  Material(const Material &) = default;
  Material &operator=(const Material &) = default;
  friend bool operator==(const std::shared_ptr<Material> &lhs,
                         const std::shared_ptr<Material> &rhs);

public:
  Color color;
  double ambient;
  double diffuse;
  double specular;
  double shininess;
  std::shared_ptr<BasePattern> pattern;
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_MATERIAL_H

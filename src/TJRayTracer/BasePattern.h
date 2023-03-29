//
// Created by tomas on 11. 2. 2023.
//

#ifndef TJRAYTRACER_BASEPATTERN_H
#define TJRAYTRACER_BASEPATTERN_H
#include "BaseObject.h"
#include "Color.h"
#include "TF.h"
#include <cmath>
#include <memory>

namespace TJRayTracer {
class BaseObject;
class BasePattern {
public:
  BasePattern();
  BasePattern(const Color &first_color, const Color &second_color);
  void SetTransform(const TJRayTracer::Matrix4d &transform);
  TJRayTracer::Matrix4d GetTransform() const;
  virtual ~BasePattern() = default;

public:
  virtual Color pattern_at(const Vector4d &point) = 0;
  Color pattern_at_object(const std::shared_ptr<BaseObject> &object,
                          const Vector4d &world_point);

public:
  Color a;
  Color b;
  Matrix4d _transform;
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_BASEPATTERN_H

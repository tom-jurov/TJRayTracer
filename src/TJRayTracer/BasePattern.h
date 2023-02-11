//
// Created by tomas on 11. 2. 2023.
//

#ifndef TJRAYTRACER_BASEPATTERN_H
#define TJRAYTRACER_BASEPATTERN_H
#include "BaseObject.h"
#include "Color.h"
#include "MatrixXd.h"
#include "TF.h"
#include <cmath>
#include <memory>

namespace TJRayTracer {
class BaseObject;
class BasePattern {
public:
  BasePattern();
  BasePattern(const Color &first_color, const Color &second_color);
  void SetTransform(const TJRayTracer::MatrixXd<double, 4, 4> &transform);
  TJRayTracer::MatrixXd<double, 4, 4> GetTransform() const;
  virtual ~BasePattern() = default;

public:
  virtual Color pattern_at(const Point &point) = 0;
  Color pattern_at_object(const std::shared_ptr<BaseObject> &object,
                          const Point &world_point);

public:
  Color a;
  Color b;
  MatrixXd<double, 4, 4> _transform;
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_BASEPATTERN_H

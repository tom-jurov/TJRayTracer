//
// Created by tomas on 12. 2. 2023.
//

#ifndef TJRAYTRACER_RINGPATTERN_H
#define TJRAYTRACER_RINGPATTERN_H
#include "TJRayTracerGlobal.h"

#include "BasePattern.h"
namespace TJRayTracer {
class TJRAYTRACER_API RingPattern : public BasePattern {
public:
  RingPattern();
  RingPattern(const Color &first_color, const Color &second_color);
  ~RingPattern() = default;

public:
  Color pattern_at(const Vector4d &point);
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_RINGPATTERN_H

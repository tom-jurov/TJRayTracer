//
// Created by tomas on 12. 2. 2023.
//

#ifndef TJRAYTRACER_RINGPATTERN_H
#define TJRAYTRACER_RINGPATTERN_H

#include "BasePattern.h"
#include "Point.h"
namespace TJRayTracer {
class RingPattern : public BasePattern {
public:
  RingPattern();
  RingPattern(const Color &first_color, const Color &second_color);
  ~RingPattern() = default;

public:
  Color pattern_at(const Point &point);
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_RINGPATTERN_H

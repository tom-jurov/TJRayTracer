//
// Created by tomas on 11. 2. 2023.
//

#ifndef TJRAYTRACER_STRIPPEDPATTERN_H
#define TJRAYTRACER_STRIPPEDPATTERN_H
#include "BasePattern.h"
namespace TJRayTracer {
class StrippedPattern : public BasePattern {
public:
  StrippedPattern();
  StrippedPattern(const Color &first_color, const Color &second_color);
  ~StrippedPattern() = default;

public:
  Color pattern_at(const Point &point);
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_STRIPPEDPATTERN_H

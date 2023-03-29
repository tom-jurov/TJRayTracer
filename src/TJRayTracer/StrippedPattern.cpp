//
// Created by tomas on 11. 2. 2023.
//

#include "StrippedPattern.h"
TJRayTracer::StrippedPattern::StrippedPattern(const Color &first_color,
                                              const Color &second_color)
    : BasePattern(first_color, second_color) {}

TJRayTracer::Color
TJRayTracer::StrippedPattern::pattern_at(const Vector4d &point) {
  if (static_cast<int>(floor(point.x())) % 2 == 0) {
    return a;
  }
  return b;
}

TJRayTracer::StrippedPattern::StrippedPattern() : BasePattern() {}

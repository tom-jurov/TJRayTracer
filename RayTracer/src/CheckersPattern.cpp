//
// Created by tomas on 12. 2. 2023.
//

#include "TJRayTracer/CheckersPattern.h"
TJRayTracer::CheckersPattern::CheckersPattern(const Color &first_color,
                                              const Color &second_color)
    : BasePattern(first_color, second_color) {}

TJRayTracer::Color
TJRayTracer::CheckersPattern::pattern_at(const Vector4d &point) {
  if (static_cast<int>(floor(point.x()) + floor(point.y()) + floor(point.z())) % 2 ==
      0) {
    return this->a;
  }
  return this->b;
}

TJRayTracer::CheckersPattern::CheckersPattern() : BasePattern() {}

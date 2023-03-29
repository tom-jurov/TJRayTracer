//
// Created by tomas on 12. 2. 2023.
//

#include "RingPattern.h"
TJRayTracer::RingPattern::RingPattern(const Color &first_color,
                                      const Color &second_color)
    : BasePattern(first_color, second_color) {}

TJRayTracer::Color TJRayTracer::RingPattern::pattern_at(const Vector4d &point) {
  if (static_cast<int>(floor(sqrt(point.x() * point.x() + point.z() * point.z()))) %
          2 ==
      0) {
    return this->a;
  }
  return this->b;
}

TJRayTracer::RingPattern::RingPattern() : BasePattern() {}

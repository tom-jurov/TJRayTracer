//
// Created by tomas on 12. 2. 2023.
//

#include "TestPattern.h"
TJRayTracer::TestPattern::TestPattern(const Color &first_color,
                                      const Color &second_color)
    : BasePattern(first_color, second_color) {}

TJRayTracer::Color TJRayTracer::TestPattern::pattern_at(const Point &point) {
  return Color(point.x, point.y, point.z);
}

TJRayTracer::TestPattern::TestPattern() : BasePattern() {}

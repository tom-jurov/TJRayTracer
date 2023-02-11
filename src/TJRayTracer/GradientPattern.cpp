//
// Created by tomas on 12. 2. 2023.
//

#include "GradientPattern.h"
TJRayTracer::GradientPattern::GradientPattern(const Color &first_color,
                                              const Color &second_color)
    : BasePattern(first_color, second_color) {}

TJRayTracer::Color
TJRayTracer::GradientPattern::pattern_at(const Point &point) {
  Color distance = this->b - this->a;
  double fraction = point.x - floor(point.x);

  return this->a + distance * fraction;
}

TJRayTracer::GradientPattern::GradientPattern() : BasePattern() {}

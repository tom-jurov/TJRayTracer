//
// Created by tomas on 12. 2. 2023.
//

#include "TJRayTracer/GradientPattern.h"
TJRayTracer::GradientPattern::GradientPattern(const Color &first_color,
                                              const Color &second_color)
    : BasePattern(first_color, second_color) {}

TJRayTracer::Color
TJRayTracer::GradientPattern::pattern_at(const Vector4d &point) {
  Color distance = this->b - this->a;
  double fraction = point.x() - floor(point.x());

  return this->a + distance * fraction;
}

TJRayTracer::GradientPattern::GradientPattern() : BasePattern() {}

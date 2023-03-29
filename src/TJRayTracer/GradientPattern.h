//
// Created by tomas on 12. 2. 2023.
//

#ifndef TJRAYTRACER_GRADIENTPATTERN_H
#define TJRAYTRACER_GRADIENTPATTERN_H

#include "BasePattern.h"
namespace TJRayTracer {
class GradientPattern : public BasePattern {
public:
  GradientPattern();
  GradientPattern(const Color &first_color, const Color &second_color);
  ~GradientPattern() = default;

public:
  Color pattern_at(const Vector4d &point);
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_GRADIENTPATTERN_H

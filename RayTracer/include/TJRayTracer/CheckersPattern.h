//
// Created by tomas on 12. 2. 2023.
//

#ifndef TJRAYTRACER_CHECKERSPATTERN_H
#define TJRAYTRACER_CHECKERSPATTERN_H

#include "TJRayTracerGlobal.h"
#include "BasePattern.h"
namespace TJRayTracer {
class TJRAYTRACER_API CheckersPattern : public BasePattern {
public:
  CheckersPattern();
  CheckersPattern(const Color &first_color, const Color &second_color);
  ~CheckersPattern() = default;

public:
  Color pattern_at(const Vector4d &point);
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_CHECKERSPATTERN_H

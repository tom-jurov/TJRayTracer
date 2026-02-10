//
// Created by tomas on 12. 2. 2023.
//

#ifndef TJRAYTRACER_TESTPATTERN_H
#define TJRAYTRACER_TESTPATTERN_H
#include "TJRayTracerGlobal.h"

#include "BasePattern.h"
namespace TJRayTracer {
class TJRAYTRACER_API TestPattern : public BasePattern {
public:
  TestPattern();
  TestPattern(const Color &first_color, const Color &second_color);
  ~TestPattern() = default;

public:
  Color pattern_at(const Vector4d &point);
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_TESTPATTERN_H

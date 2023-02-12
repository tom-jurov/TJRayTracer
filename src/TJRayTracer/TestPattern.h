//
// Created by tomas on 12. 2. 2023.
//

#ifndef TJRAYTRACER_TESTPATTERN_H
#define TJRAYTRACER_TESTPATTERN_H

#include "BasePattern.h"
#include "Point.h"
namespace TJRayTracer {
class TestPattern : public BasePattern {
public:
  TestPattern();
  TestPattern(const Color &first_color, const Color &second_color);
  ~TestPattern() = default;

public:
  Color pattern_at(const Point &point);
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_TESTPATTERN_H

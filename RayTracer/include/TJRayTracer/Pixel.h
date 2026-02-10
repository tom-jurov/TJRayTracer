//
// Created by tomas on 1. 2. 2023.
//

#ifndef TJRAYTRACER_PIXEL_H
#define TJRAYTRACER_PIXEL_H
#include "TJRayTracerGlobal.h"
#include "Color.h"
namespace TJRayTracer {
class TJRAYTRACER_API Pixel {
private:
  int _x;
  int _y;
  Color _color;

public:
  Pixel() = default;
  Pixel(int x, int y, Color color);
  ~Pixel() = default;
  int GetX() const;
  int GetY() const;
  Color GetColor() const;
  bool SetColor(const Color &color);
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_PIXEL_H

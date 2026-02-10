//
// Created by tomas on 1. 2. 2023.
//

#ifndef TJRAYTRACER_CANVAS_H
#define TJRAYTRACER_CANVAS_H
#include "TJRayTracerGlobal.h"
#include "Pixel.h"
#include <memory>
#include <string>
namespace TJRayTracer {
class TJRAYTRACER_API Canvas {
private:
  int _width;
  int _height;
  Pixel *_pixels = nullptr;

public:
  Canvas(int width, int height);
  ~Canvas();
  int GetWidth() const;
  int GetHeight() const;
  Color GetPixelColor(int x, int y) const;
  bool SetPixelColor(int x, int y, const Color &color);
  bool RenderPng(const std::string &filename);
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_CANVAS_H

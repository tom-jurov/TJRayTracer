//
// Created by tomas on 1. 2. 2023.
//

#include "Pixel.h"
TJRayTracer::Pixel::Pixel(int x, int y, Color color)
    : _x(x), _y(y), _color(color) {}

int TJRayTracer::Pixel::GetX() const { return _x; }

int TJRayTracer::Pixel::GetY() const { return _y; }

TJRayTracer::Color TJRayTracer::Pixel::GetColor() const { return _color; }

bool TJRayTracer::Pixel::SetColor(const Color &color) {
  if (&color != nullptr) {
    _color.red = color.red;
    _color.green = color.green;
    _color.blue = color.blue;
    return true;
  }
  return false;
}
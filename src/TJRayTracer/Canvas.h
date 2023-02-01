//
// Created by tomas on 1. 2. 2023.
//

#ifndef TJRAYTRACER_CANVAS_H
#define TJRAYTRACER_CANVAS_H
#include <memory>
#include <string>
#include "Pixel.h"
namespace TJRayTracer {
    class Canvas {
    private:
        int _width;
        int _height;
        Pixel* _pixels = nullptr;
    public:
        Canvas(int width, int height);
        ~Canvas();
        int GetWidth() const;
        int GetHeight() const;
        Color GetPixelColor(int x, int y) const;
        bool SetPixelColor(int x, int y, const Color& color);
        bool RenderPng(const std::string &filename);
    };
}


#endif //TJRAYTRACER_CANVAS_H

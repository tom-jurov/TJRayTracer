//
// Created by tomas on 1. 2. 2023.
//
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Canvas.h"
#include <algorithm>
#include "stb_image_write.h"
#include <iostream>

TJRayTracer::Canvas::Canvas(int width, int height) : _width(width), _height(height)
{
    _pixels = new Pixel[width*height];
    for (int y=0; y<height; ++y){
        for (int x=0; x<width; ++x)
        {
            _pixels[x+width*y] = Pixel(x,y,Color(0,0,0));
        }
    }
}

TJRayTracer::Canvas::~Canvas()
{
    delete[] _pixels;
}

int TJRayTracer::Canvas::GetWidth() const
{
    return _width;
}

int TJRayTracer::Canvas::GetHeight() const
{
    return _height;
}

TJRayTracer::Color TJRayTracer::Canvas::GetPixelColor(int x, int y) const
{
    return _pixels[x+_width*y].GetColor();
}

bool TJRayTracer::Canvas::SetPixelColor(int x, int y, const TJRayTracer::Color& color)
{
    if(x<_width && y<_height) {
        _pixels[x + _width * y].SetColor(color);
        return true;
    }
    return false;
}

bool TJRayTracer::Canvas::RenderPng(const std::string &filename)
{
    uint8_t* deserialized_pixels = new uint8_t[_width*_height*3];
    int index = 0;
    for(int y=0; y<_height; ++y) {
        for (int x = 0; x < _width; ++x) {
            deserialized_pixels[index++] = std::min(std::max((static_cast<int>(GetPixelColor(x,y).red * 255)),0),255);
            deserialized_pixels[index++] = std::min(std::max((static_cast<int>(GetPixelColor(x,y).green * 255)),0),255);
            deserialized_pixels[index++] = std::min(std::max((static_cast<int>(GetPixelColor(x,y).blue * 255)),0),255);
        }
    }
    int result = stbi_write_png((filename+".png").c_str(), _width, _height, 3, deserialized_pixels,_width * 3);
    delete[] deserialized_pixels;
    return result;
}
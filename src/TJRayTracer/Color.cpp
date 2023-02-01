//
// Created by tomas on 1. 2. 2023.
//

#include "Color.h"
#include "Equal.h"


TJRayTracer::Color::Color() : red(0.0) , green(0.0), blue(0.0){}
TJRayTracer::Color::Color(double red, double green, double blue) : red(red), green(green), blue(blue){}
TJRayTracer::Color::~Color() noexcept {}


TJRayTracer::Color TJRayTracer::operator+(const TJRayTracer::Color &lhs, const TJRayTracer::Color &rhs) {
    TJRayTracer::Color result;
    if(&lhs != nullptr && &rhs!= nullptr)
    {
        result.red = lhs.red + rhs.red;
        result.green = lhs.green + rhs.green;
        result.blue = lhs.blue + rhs.blue;
    }
    return result;
}

TJRayTracer::Color TJRayTracer::operator-(const TJRayTracer::Color &lhs, const TJRayTracer::Color &rhs) {
    TJRayTracer::Color result;
    if(&lhs != nullptr && &rhs!= nullptr)
    {
        result.red = lhs.red - rhs.red;
        result.green = lhs.green - rhs.green;
        result.blue = lhs.blue - rhs.blue;
    }
    return result;
}

bool TJRayTracer::operator== (const TJRayTracer::Color &lhs,const TJRayTracer::Color &rhs)
{
    if(&lhs!= nullptr && &rhs!= nullptr){
        if(equal(lhs.red, rhs.red) &&
           equal(lhs.green, rhs.green) &&
           equal(lhs.blue, rhs.blue)){
            return true;
        }
    }
    return false;
}

TJRayTracer::Color TJRayTracer::Color::operator*(const double &scalar) const{
    TJRayTracer::Color result;
    if(this != nullptr) {
        result.red = this->red * scalar;
        result.green = this->green * scalar;
        result.blue = this->blue * scalar;
    }
    return result;
}

TJRayTracer::Color TJRayTracer::operator*(const double &scalar, const TJRayTracer::Color &rhs) {
    return (rhs * scalar);
}

TJRayTracer::Color TJRayTracer::operator*(const TJRayTracer::Color &lhs, const TJRayTracer::Color &rhs) {
    TJRayTracer::Color result;
    if(&lhs != nullptr && &rhs!= nullptr)
    {
        result.red = lhs.red * rhs.red;
        result.green = lhs.green * rhs.green;
        result.blue = lhs.blue * rhs.blue;
    }
    return result;
}

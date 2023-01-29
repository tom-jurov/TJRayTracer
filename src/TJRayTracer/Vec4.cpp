//
// Created by tomas on 28. 1. 2023.
//
#include "Vec4.h"
#include "Equal.h"

TJRayTracer::Vec4::Vec4(): x(0.0), y(0.0), z(0.0), w(0.0) {}

TJRayTracer::Vec4::Vec4(double x, double y, double z, double w)
                       : x(x), y(y), z(z), w(w)
{
}

TJRayTracer::Vec4::Vec4(const Vec4 &other)
                       : x(other.x), y(other.y), z(other.z), w(other.w)
{
}

TJRayTracer::Vec4::~Vec4() {}

bool TJRayTracer::Vec4::IsVector() const
{
    return (equal(this->w, 0.0));
}

bool TJRayTracer::Vec4::IsPoint() const{
    return (equal(this->w, 1.0));
}

bool TJRayTracer::operator== (const TJRayTracer::Vec4 &lhs,const TJRayTracer::Vec4 &rhs)
{
    if(&lhs!= nullptr && &rhs!= nullptr){
        if(equal(lhs.x, rhs.x) &&
           equal(lhs.y, rhs.y) &&
           equal(lhs.z, rhs.z) &&
           equal(lhs.w, rhs.w)){
            return true;
        }
    }
    return false;
}


TJRayTracer::Vec4 TJRayTracer::Vec4::operator-() {
    if(this != nullptr)
    {
            this->x = -this->x;
            this->y = -this->y;
            this->z = -this->z;
            this->w = -this->w;
    }
    return *this;
}

TJRayTracer::Vec4 TJRayTracer::operator+(const TJRayTracer::Vec4 &lhs, const TJRayTracer::Vec4 &rhs) {
    TJRayTracer::Vec4 result;
    if(&lhs != nullptr && &rhs!= nullptr)
    {
        if(!(lhs.IsPoint() && rhs.IsPoint()))
        {
            result.x = lhs.x + rhs.x;
            result.y = lhs.y + rhs.y;
            result.z = lhs.z + rhs.z;
            result.w = lhs.w + rhs.w;
        }
        else
        {
            std::cout << "Can't add two points together" << std::endl;
        }
    }
    return result;
}

TJRayTracer::Vec4 TJRayTracer::operator-(const TJRayTracer::Vec4 &lhs, const TJRayTracer::Vec4 &rhs) {
    TJRayTracer::Vec4 result;
    if(&lhs != nullptr && &rhs!= nullptr)
    {
        if(!(lhs.IsVector() && rhs.IsPoint()))
        {
            result.x = lhs.x - rhs.x;
            result.y = lhs.y - rhs.y;
            result.z = lhs.z - rhs.z;
            result.w = lhs.w - rhs.w;
        }
        else
        {
            std::cout << "Can't subtract point from vector" << std::endl;
        }
    }
    return result;
}

TJRayTracer::Vec4 TJRayTracer::Vec4::operator*(const double &scalar) const{
    TJRayTracer::Vec4 result;
    if(this != nullptr) {
        result.x = this->x * scalar;
        result.y = this->y * scalar;
        result.z = this->z * scalar;
        result.w = this->w * scalar;
    }
    return result;
}

TJRayTracer::Vec4 TJRayTracer::operator*(const double &scalar, const TJRayTracer::Vec4 &rhs) {
    return (rhs * scalar);
}

TJRayTracer::Vec4 TJRayTracer::Vec4::operator/(const double &scalar) const {
    TJRayTracer::Vec4 result;
    if(this != nullptr) {
        result.x = this->x / scalar;
        result.y = this->y / scalar;
        result.z = this->z / scalar;
        result.w = this->w / scalar;
    }
    return result;
}

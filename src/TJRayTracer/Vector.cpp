//
// Created by tomas on 29. 1. 2023.
//

#include "Vector.h"
#include <cmath>
#include "Equal.h"

TJRayTracer::Vector::Vector() : Vec4(0.0, 0.0, 0.0, 0.0){}
TJRayTracer::Vector::Vector(double x, double y, double z) : Vec4(x, y, z, 0.0) {}
TJRayTracer::Vector::~Vector() noexcept {}

namespace TJRayTracer
{
    Vector Vector::operator-() {
        if(this != nullptr)
        {
            this->x = -this->x;
            this->y = -this->y;
            this->z = -this->z;
        }
        return *this;
    }

    Vector operator+(const Vector &lhs, const Vector &rhs) {
        Vector result;
        if(&lhs != nullptr && &rhs!= nullptr)
        {
            result.x = lhs.x + rhs.x;
            result.y = lhs.y + rhs.y;
            result.z = lhs.z + rhs.z;
        }
        return result;
    }

    Vector operator-(const Vector &lhs, const Vector &rhs) {
        Vector result;
        if(&lhs != nullptr && &rhs!= nullptr)
        {
            result.x = lhs.x - rhs.x;
            result.y = lhs.y - rhs.y;
            result.z = lhs.z - rhs.z;
        }
        return result;
    }

    Vector Vector::operator*(const double &scalar) const{
        Vector result;
        if(this != nullptr) {
            result.x = this->x * scalar;
            result.y = this->y * scalar;
            result.z = this->z * scalar;
        }
        return result;
    }

    Vector operator*(const double &scalar, const Vector &rhs) {
        return (rhs * scalar);
    }

    Vector Vector::operator/(const double &scalar) const {
        Vector result;
        if(this != nullptr) {
            result = (*this) * (1/scalar);
        }
        return result;
    }

}


double TJRayTracer::Vector::magnitude(const TJRayTracer::Vector &vector) {
    double result = 0;
    if(&vector != nullptr)
    {
        result = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    }
    return result;
}

double TJRayTracer::Vector::dot(const TJRayTracer::Vector &lhs, const TJRayTracer::Vector &rhs) {
    double result;
    if(!(&lhs == nullptr && &rhs == nullptr))
    {
        result = lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }
    return result;
}

TJRayTracer::Vector TJRayTracer::Vector::cross(const TJRayTracer::Vector &lhs, const TJRayTracer::Vector &rhs) {
    Vector result;
    if(!(&lhs == nullptr && &rhs == nullptr))
    {
        result.x = lhs.y * rhs.z - lhs.z * rhs.y;
        result.y = lhs.z * rhs.x - lhs.x * rhs.z;
        result.z = lhs.x * rhs.y - lhs.y * rhs.x;
    }
    return result;
}

TJRayTracer::Vector TJRayTracer::Vector::normalize() const {
    double mg = TJRayTracer::Vector::magnitude(*this);
    if(!equal(mg,0))
    {
        return (*this) / mg;
    }
    return (*this);
}

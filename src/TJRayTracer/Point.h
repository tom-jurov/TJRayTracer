//
// Created by tomas on 29. 1. 2023.
//

#ifndef TJRAYTRACER_POINT_H
#define TJRAYTRACER_POINT_H
#include "Vector.h"
#include "Vec4.h"

namespace TJRayTracer {
    class Vector;
    class Point : public Vec4{
    public:
        Point();
        Point(double x, double y, double z);
        ~Point();

    public:
        friend Point operator+(const Point &lhs, const Vector &rhs);
        friend Point operator-(const Point &lhs, const Vector &rhs);
        friend Vector operator-(const Point &lhs, const Point &rhs);
    };
}


#endif //TJRAYTRACER_POINT_H

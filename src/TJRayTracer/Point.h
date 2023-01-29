//
// Created by tomas on 29. 1. 2023.
//

#ifndef TJRAYTRACER_POINT_H
#define TJRAYTRACER_POINT_H
#include "Vec4.h"

namespace TJRayTracer {
    class Point : public Vec4{
    public:
        Point();
        Point(double x, double y, double z);
        ~Point();
    };
}


#endif //TJRAYTRACER_POINT_H

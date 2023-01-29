//
// Created by tomas on 28. 1. 2023.
//

#ifndef TJRAYTRACER_VEC4_H
#define TJRAYTRACER_VEC4_H
#include <iostream>

namespace TJRayTracer{
    class Vec4 {
    public:
        double x, y, z, w;
    public:
        Vec4();
        Vec4(double x, double y, double z, double w);
        Vec4(const Vec4 &other);
        ~Vec4();
        bool IsPoint();
        bool IsVector();
    };
}


#endif //TJRAYTRACER_VEC4_H

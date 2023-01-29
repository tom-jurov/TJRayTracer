//
// Created by tomas on 29. 1. 2023.
//

#ifndef TJRAYTRACER_VECTOR_H
#define TJRAYTRACER_VECTOR_H
#include "Vec4.h"

namespace TJRayTracer{
    class Vector : public Vec4{
    public:
        Vector();
        Vector(double x, double y, double z);
        ~Vector();
    };
}


#endif //TJRAYTRACER_VECTOR_H

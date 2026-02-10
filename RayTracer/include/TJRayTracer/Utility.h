#ifndef TJRAYTRACER_UTILITY_H
#define TJRAYTRACER_UTILITY_H
#include "TJRayTracerGlobal.h"
#include <Eigen/Dense>

namespace TJRayTracer{
    typedef Eigen::Matrix4d Matrix4d;
    typedef Eigen::Vector4d Vector4d;
    TJRayTracer::Vector4d
    inline reflect(const TJRayTracer::Vector4d &in,
                             const TJRayTracer::Vector4d &normal) {
        return in - normal * 2 * in.dot(normal);
    }
}
#endif
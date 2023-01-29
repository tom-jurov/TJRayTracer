//
// Created by tomas on 29. 1. 2023.
//

#include "Vector.h"

TJRayTracer::Vector::Vector() : Vec4(0.0, 0.0, 0.0, 0.0){}
TJRayTracer::Vector::Vector(double x, double y, double z) : Vec4(x, y, z, 0.0) {}
TJRayTracer::Vector::~Vector() noexcept {}

//
// Created by tomas on 29. 1. 2023.
//

#include "Point.h"

TJRayTracer::Point::Point() : Vec4(0.0, 0.0, 0.0, 1.0){}
TJRayTracer::Point::Point(double x, double y, double z) : Vec4(x, y, z, 1.0) {}
TJRayTracer::Point::~Point() noexcept {}

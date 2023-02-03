//
// Created by tomas on 29. 1. 2023.
//
#include <iostream>
#include "TJRayTracer/Vec4.h"
#include "TJRayTracer/Vector.h"
#include "TJRayTracer/Point.h"
#include "TJRayTracer/Canvas.h"
#include "TJRayTracer/MatrixXd.h"
#include "TJRayTracer/TF.h"
#include <vector>

int main()
{
    std::vector<TJRayTracer::Point> points;
    for (std::size_t i=0; i<12; ++i) {
        points.push_back(TJRayTracer::Point(0, 0, 0));
    }
    double angle = 0;
    TJRayTracer::Canvas c(900,550);
    for(auto& p: points)
    {
        auto translation = TJRayTracer::TF::translation(100,0,0);
        auto rotation_around_y = TJRayTracer::TF::rotation_y(angle);
        angle += M_PI/6;
        auto rotation_around_x = TJRayTracer::TF::rotation_x(-M_PI_2);
        p = (rotation_around_x*rotation_around_y*translation)*p;
        c.SetPixelColor(450+static_cast<int>(p.x),275-static_cast<int>(p.y),TJRayTracer::Color(1,0,0));
    }

    c.RenderPng("test");
    std::cin.get();
    return 0;
}

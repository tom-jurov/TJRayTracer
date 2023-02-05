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
#include "TJRayTracer/BaseObject.h"
#include "TJRayTracer/Sphere.h"
#include <vector>

int main()
{
    int width = 1000;
    int height = 1000;
    int wall_size = 10;
    double half = wall_size/2;
    double wall_z = 10;
    double pixel_size = (double)wall_size/height;
    TJRayTracer::Canvas canvas(width,height);
    TJRayTracer::Color red(1,0,0);
    TJRayTracer::BaseObject *shape = new TJRayTracer::Sphere();
    shape->SetTransform(TJRayTracer::TF::scaling(1.2,1.2,1.2));
    TJRayTracer::Point ray_origin(0,0,-5);
    for (std::size_t y=0; y<height; ++y)
    {
        double world_y = half - pixel_size*y;
        for (std::size_t x=0; x<width; ++x)
        {
            double world_x = double(-half + pixel_size*x);
            auto position = TJRayTracer::Point(world_x, world_y, wall_z);

            auto r = TJRayTracer::Ray(ray_origin,(position-ray_origin).normalize());
            auto xs = shape->intersect(r);
            if (shape->hit(xs).object!= nullptr)
            {
                canvas.SetPixelColor(x,y,red);
            }
        }
    }

    canvas.RenderPng("test");
    delete(shape);
    return 0;
}

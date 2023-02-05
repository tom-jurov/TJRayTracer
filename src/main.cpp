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
#include "TJRayTracer/Material.h"
#include "TJRayTracer/PointLight.h"
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
    TJRayTracer::BaseObject *shape = new TJRayTracer::Sphere();
    shape->material = TJRayTracer::Material();
    shape->material.color = TJRayTracer::Color(1,0.2,1);
    TJRayTracer::Point light_position(-10, 10, -10);
    TJRayTracer::Color light_color(1,1,1);
    TJRayTracer::PointLight light(std::move(light_position), std::move(light_color));
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
            auto hit = shape->hit(xs);
            if (hit.object!= nullptr)
            {
                auto point = r.position(hit.t);
                auto normal = shape->normal_at(point);
                auto direction_of_ray = r.GetDirection();
                auto eye = -direction_of_ray;
                auto color = TJRayTracer::PointLight::lighting(hit.object->material, light, point, eye, normal);
                canvas.SetPixelColor(x,y,color);
            }
        }
    }

    canvas.RenderPng("test");
    delete(shape);
    return 0;
}

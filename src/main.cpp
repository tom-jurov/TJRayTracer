//
// Created by tomas on 29. 1. 2023.
//
#include <iostream>
#include "TJRayTracer/Vec4.h"
#include "TJRayTracer/Vector.h"
#include "TJRayTracer/Point.h"
#include "TJRayTracer/Canvas.h"
#include "TJRayTracer/MatrixXd.h"
#include <vector>

struct Environment{
    TJRayTracer::Vector gravity;
    TJRayTracer::Vector wind;
};

struct Projectile{
    TJRayTracer::Point position;
    TJRayTracer::Vector velocity;
};

void tick(Environment &env, Projectile &proj)
{
    proj.position = proj.position + proj.velocity;
    proj.velocity = proj.velocity + env.gravity + env.wind;
}

int main()
{
    Projectile p{TJRayTracer::Point(0,1,0), 11.25*TJRayTracer::Vector(1,1.8,0).normalize()};
    Environment e{TJRayTracer::Vector(0, -0.1, 0), TJRayTracer::Vector(-0.01,0,0)};
    TJRayTracer::Canvas c(900,550);
    for(int i =0; i< 200; ++i) {
        c.SetPixelColor(p.position.x,550-p.position.y,TJRayTracer::Color(1,0,0));
        tick(e, p);
    }
    c.RenderPng("test");
    std::cin.get();
    return 0;
}

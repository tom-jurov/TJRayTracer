//
// Created by tomas on 29. 1. 2023.
//
#include <iostream>
#include "TJRayTracer/Vec4.h"
#include "TJRayTracer/Vector.h"
#include <vector>

struct Environment{
    TJRayTracer::Vector gravity;
    TJRayTracer::Vector wind;
};

struct Projectile{
    TJRayTracer::Point position;
    TJRayTracer::Vector velocity;
};

Projectile tick(Environment &env, Projectile &proj)
{
    TJRayTracer::Point position = proj.position + proj.velocity;
    TJRayTracer::Vector velocity = proj.velocity + env.gravity + env.wind;
    return Projectile{position,velocity};
}

int main()
{
    Projectile p{TJRayTracer::Point(0,1,0), TJRayTracer::Vector(1,1,0).normalize()};
    Environment e{TJRayTracer::Vector(0, -0.1, 0), TJRayTracer::Vector(-0.01,0,0)};
    std::cin.get();
    return 0;
}

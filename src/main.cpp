//
// Created by tomas on 29. 1. 2023.
//
#include <iostream>
#include "TJRayTracer/Vec4.h"
#include "TJRayTracer/Vector.h"
#include "TJRayTracer/Point.h"
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
    Projectile p{TJRayTracer::Point(0,1,0), TJRayTracer::Vector(1,1,0).normalize()};
    Environment e{TJRayTracer::Vector(0, -0.1, 0), TJRayTracer::Vector(-0.01,0,0)};
    for(int i =0; i< 143; ++i) {
        tick(e, p);
        std::cout << p.position.x << " " << p.position.y << " " << p.position.z << std::endl;
        std::cout << p.velocity.x << " " << p.velocity.y << " " << p.velocity.z << std::endl;
    }
    std::cin.get();
    return 0;
}

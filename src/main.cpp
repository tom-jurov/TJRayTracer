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
#include "TJRayTracer/World.h"
#include "TJRayTracer/Camera.h"
#include <vector>

int main()
{
    std::shared_ptr<TJRayTracer::BaseObject> floor = std::make_shared<TJRayTracer::Sphere>();
    floor->SetTransform(TJRayTracer::TF::scaling(10,0.01,10));
    floor->material = TJRayTracer::Material();
    floor->material.color = TJRayTracer::Color(1, 0.9, 0.9);
    floor->material.specular = 0;

    std::shared_ptr<TJRayTracer::BaseObject> left_wall = std::make_shared<TJRayTracer::Sphere>();
    left_wall->SetTransform(TJRayTracer::TF::translation(0,0,5)*TJRayTracer::TF::rotation_y(-M_PI_4)*TJRayTracer::TF::rotation_x(M_PI_2)*TJRayTracer::TF::scaling(10,0.01,10));
    left_wall->material = TJRayTracer::Material();

    std::shared_ptr<TJRayTracer::BaseObject> right_wall = std::make_shared<TJRayTracer::Sphere>();
    right_wall->SetTransform(TJRayTracer::TF::translation(0,0,5)*TJRayTracer::TF::rotation_y(M_PI_4)*TJRayTracer::TF::rotation_x(M_PI_2)*TJRayTracer::TF::scaling(10,0.01,10));
    right_wall->material = TJRayTracer::Material();

    std::shared_ptr<TJRayTracer::BaseObject> middle = std::make_shared<TJRayTracer::Sphere>();
    middle->SetTransform(TJRayTracer::TF::translation(-0.5,1,0.5));
    middle->material = TJRayTracer::Material();
    middle->material.color = TJRayTracer::Color(0.1,1,0.5);
    middle->material.diffuse = 0.7;
    middle->material.specular = 0.3;

    std::shared_ptr<TJRayTracer::BaseObject> right = std::make_shared<TJRayTracer::Sphere>();
    right->SetTransform(TJRayTracer::TF::translation(1.5,0.5,-0.5)*TJRayTracer::TF::scaling(0.5,0.5,0.5));
    right->material = TJRayTracer::Material();
    right->material.color = TJRayTracer::Color(0.5,1,0.1);
    right->material.diffuse = 0.7;
    right->material.specular = 0.3;

    std::shared_ptr<TJRayTracer::BaseObject> left = std::make_shared<TJRayTracer::Sphere>();
    left->SetTransform(TJRayTracer::TF::translation(-1.5,0.33,-0.75)*TJRayTracer::TF::scaling(0.33,0.33,0.33));
    left->material = TJRayTracer::Material();
    left->material.color = TJRayTracer::Color(1,0.8,0.1);
    left->material.diffuse = 0.7;
    left->material.specular = 0.3;

    TJRayTracer::World world;
    world.objects.push_back(floor);
    world.objects.push_back(left_wall);
    world.objects.push_back(right_wall);
    world.objects.push_back(middle);
    world.objects.push_back(right);
    world.objects.push_back(left);
    world.light_sources.push_back(TJRayTracer::PointLight(TJRayTracer::Point(-10,10,-10),TJRayTracer::Color(1,1,1)));
    TJRayTracer::Camera camera(3840,2160, M_PI/3);
    camera.tf = TJRayTracer::TF::view_transform(TJRayTracer::Point(0,1.5,-5),TJRayTracer::Point(0,1,0), TJRayTracer::Vector(0,1,0));
    TJRayTracer::Canvas canvas = camera.render(world);
    canvas.RenderPng("test");
    return 0;
}

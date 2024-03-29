//
// Created by tomas on 29. 1. 2023.
//
#include "TJRayTracer/BaseObject.h"
#include "TJRayTracer/Camera.h"
#include "TJRayTracer/Canvas.h"
#include "TJRayTracer/CheckersPattern.h"
#include "TJRayTracer/GradientPattern.h"
#include "TJRayTracer/Material.h"
#include "TJRayTracer/Plane.h"
#include "TJRayTracer/PointLight.h"
#include "TJRayTracer/Sphere.h"
#include "TJRayTracer/TF.h"
#include "TJRayTracer/World.h"
#include "TJRayTracer/Cube.h"
#include "TJRayTracer/Cones.h"
#include "TJRayTracer/RingPattern.h"
#include <iostream>
#include <vector>

#ifdef _WIN32
#define M_PI 3.14159265358979323846
#define M_PI_4 3.14159265358979323846/4
#define M_PI_2 3.14159265358979323846/2
#endif

int main() {
  std::shared_ptr<TJRayTracer::BasePattern> pattern =
      std::make_shared<TJRayTracer::CheckersPattern>(
          TJRayTracer::Color(1, 1, 1), TJRayTracer::Color(0, 0, 0));
  pattern->SetTransform(TJRayTracer::TF::scaling(0.5, 0.5, 0.5));
  std::shared_ptr<TJRayTracer::BaseObject> floor =
      std::make_shared<TJRayTracer::Plane>();
  floor->SetTransform(TJRayTracer::TF::scaling(1, 1, 1));
  floor->material = std::make_shared<TJRayTracer::Material>();
  floor->material->reflective = 0.5;
  floor->material->pattern = pattern;
  floor->material->color = TJRayTracer::Color(1, 0.9, 0.9);
  floor->material->specular = 0;

  std::shared_ptr<TJRayTracer::BaseObject> top_wall =
      std::make_shared<TJRayTracer::Plane>();
  top_wall->SetTransform(TJRayTracer::TF::rotation_z(-M_PI / 6) *
                         TJRayTracer::TF::translation(0, 3, 0));
  top_wall->material = std::make_shared<TJRayTracer::Material>();
  top_wall->material->pattern = pattern;
  top_wall->material->color = TJRayTracer::Color(1, 0.9, 0.9);
  top_wall->material->specular = 0;

  std::shared_ptr<TJRayTracer::BaseObject> left_wall =
      std::make_shared<TJRayTracer::Plane>();
  left_wall->SetTransform(TJRayTracer::TF::translation(0, 0, 5) *
                          TJRayTracer::TF::rotation_y(-M_PI_4) *
                          TJRayTracer::TF::rotation_x(M_PI_2) *
                          TJRayTracer::TF::scaling(1, 1, 1));
  left_wall->material = std::make_shared<TJRayTracer::Material>();
  left_wall->material->pattern = pattern;

  std::shared_ptr<TJRayTracer::BaseObject> right_wall =
      std::make_shared<TJRayTracer::Plane>();
  right_wall->SetTransform(TJRayTracer::TF::translation(0, 0, 5) *
                           TJRayTracer::TF::rotation_y(M_PI_4) *
                           TJRayTracer::TF::rotation_x(M_PI_2) *
                           TJRayTracer::TF::scaling(1, 1, 1));
  right_wall->material = std::make_shared<TJRayTracer::Material>();
  right_wall->material->pattern = pattern;

  std::shared_ptr<TJRayTracer::Cones> middle =
      std::make_shared<TJRayTracer::Cones>();
  middle->SetClosed(true);    
  middle->SetMaximum(0.5);
  middle->SetMinimum(0);
  middle->SetTransform(TJRayTracer::TF::translation(-0.5, 1, 0.5)*TJRayTracer::TF::rotation_z(M_PI));
  middle->material = std::make_shared<TJRayTracer::Material>();
  middle->material->color = TJRayTracer::Color(0.1, 1, 0.5);
  middle->material->diffuse = 0.7;
  middle->material->specular = 0.3;

  std::shared_ptr<TJRayTracer::BaseObject> right =
      std::make_shared<TJRayTracer::Sphere>();
  right->SetTransform(TJRayTracer::TF::translation(1.5, 0.5, -0.5) *
                      TJRayTracer::TF::scaling(0.5, 0.5, 0.5));
  right->material = std::make_shared<TJRayTracer::Material>();
  right->material->pattern = pattern;
  right->material->color = TJRayTracer::Color(0.5, 1, 0.1);
  right->material->diffuse = 0.7;
  right->material->specular = 0.3;

  std::shared_ptr<TJRayTracer::BaseObject> left =
      std::make_shared<TJRayTracer::Sphere>();
  left->SetTransform(TJRayTracer::TF::translation(-1.5, 0.33, -0.75) *
                     TJRayTracer::TF::scaling(0.33, 0.33, 0.33));
  left->material = std::make_shared<TJRayTracer::Material>();
  left->material->pattern = pattern;
  left->material->color = TJRayTracer::Color(1, 0.8, 0.1);
  left->material->diffuse = 0.7;
  left->material->specular = 0.3;

  TJRayTracer::World world;
  world.objects.push_back(floor);
  world.objects.push_back(left_wall);
  world.objects.push_back(right_wall);
  world.objects.push_back(middle);
  world.objects.push_back(right);
  world.objects.push_back(left);
  world.objects.push_back(top_wall);
  world.light_sources.push_back(TJRayTracer::PointLight(
      TJRayTracer::Vector4d(-10, 1.6, -10, 1), TJRayTracer::Color(1, 1, 1)));
  TJRayTracer::Camera camera(1280, 720, M_PI / 3);
  camera.tf = TJRayTracer::TF::view_transform(TJRayTracer::Vector4d(0, 0.5, -5, 1),
                                              TJRayTracer::Vector4d(0, 1, 0, 1),
                                              TJRayTracer::Vector4d(0, 1, 0, 0));
  TJRayTracer::Canvas canvas = camera.render(world);
  canvas.RenderPng("test");
  return 0;
}

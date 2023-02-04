//
// Created by tomas on 3. 2. 2023.
//

#include "Sphere.h"
#include <iostream>
TJRayTracer::Sphere::Sphere() : BaseObject(){}
TJRayTracer::Sphere::Sphere(const TJRayTracer::MatrixXd<double,4,4>& transform) : BaseObject(transform){}
TJRayTracer::Sphere::~Sphere() noexcept {}

std::vector<TJRayTracer::Intersection> TJRayTracer::Sphere::intersect(const TJRayTracer::Ray &ray) {
    auto object_ray = ray.transform(this->GetTransform().inverse());
    auto sphereOrigin = Point(0,0,0);
    std::vector<Intersection> intersections;
    Vector sphere_to_ray = object_ray.GetOrigin() - sphereOrigin;
    double a = Vector::dot(object_ray.GetDirection(), object_ray.GetDirection());
    double b = 2 * Vector::dot(object_ray.GetDirection(), sphere_to_ray);
    double c = Vector::dot(sphere_to_ray, sphere_to_ray) - 1;

    double discriminant = b*b - 4*a*c;
    if (discriminant< 0)
    {
    }
    else
    {
        double t1 = (-b-sqrt(discriminant))/(2*a);
        double t2 =(-b+sqrt(discriminant))/(2*a);
        intersections.push_back(Intersection(t1, this));
        intersections.push_back(Intersection(t2,this));
    }
    return intersections;
}

//
// Created by tomas on 3. 2. 2023.
//

#include "Sphere.h"
TJRayTracer::Sphere::Sphere() : BaseObject() {}
TJRayTracer::Sphere::Sphere(
    const TJRayTracer::MatrixXd<double, 4, 4> &transform)
    : BaseObject(transform) {}
TJRayTracer::Sphere::~Sphere() noexcept {}

std::vector<TJRayTracer::Intersection>
TJRayTracer::Sphere::local_intersect(const Ray &local_ray) {
  auto sphereOrigin = Point(0, 0, 0);
  std::vector<Intersection> intersections;
  Vector sphere_to_ray = local_ray.GetOrigin() - sphereOrigin;
  double a = Vector::dot(local_ray.GetDirection(), local_ray.GetDirection());
  double b = 2 * Vector::dot(local_ray.GetDirection(), sphere_to_ray);
  double c = Vector::dot(sphere_to_ray, sphere_to_ray) - 1;

  double discriminant = b * b - 4 * a * c;
  if (discriminant < 0) {
  } else {
    double t1 = (-b - sqrt(discriminant)) / (2 * a);
    double t2 = (-b + sqrt(discriminant)) / (2 * a);
    intersections.push_back(Intersection(t1, std::make_shared<Sphere>(*this)));
    intersections.push_back(Intersection(t2, std::make_shared<Sphere>(*this)));
  }
  return intersections;
}

TJRayTracer::Vector
TJRayTracer::Sphere::local_normal_at(const TJRayTracer::Point &local_point) {
  Vector local_normal = local_point - Point(0, 0, 0);
  return local_normal;
}

std::shared_ptr<TJRayTracer::Sphere> TJRayTracer::Sphere::Glass_sphere() {
  auto sphere = std::make_shared<Sphere>();
  sphere->SetTransform(TF::identity());
  sphere->material->transparency = 1.0;
  sphere->material->refractive_index = 1.5;
  return sphere;
}

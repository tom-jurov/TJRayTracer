#include "Cylinder.h"
#include "Equal.h"
TJRayTracer::Cylinder::Cylinder() : BaseObject() {}
TJRayTracer::Cylinder::Cylinder(
    const TJRayTracer::MatrixXd<double, 4, 4> &transform)
    : BaseObject(transform) {}
TJRayTracer::Cylinder::~Cylinder() noexcept {}

std::vector<TJRayTracer::Intersection>
TJRayTracer::Cylinder::local_intersect(const Ray &local_ray) {
    double a = pow(local_ray.GetDirection().x, 2) + pow(local_ray.GetDirection().z, 2);

    if (equal(a,0))
    {
        return {};
    }

    double b = 2 * local_ray.GetOrigin().x * local_ray.GetDirection().x +
               2 * local_ray.GetOrigin().z * local_ray.GetDirection().z;
    double c = pow(local_ray.GetOrigin().x, 2)  + pow(local_ray.GetOrigin().z, 2) - 1;

    double disc = b * b - 4 * a * c;

    if (disc < 0)
    {
        return {};
    }

    double t0 = (-b - sqrt(disc)) / (2 * a);
    double t1 = (-b + sqrt(disc)) / (2 * a);

    return {Intersection(t0, std::make_shared<Cylinder>(*this)), Intersection(t1, std::make_shared<Cylinder>(*this))};
}

TJRayTracer::Vector
TJRayTracer::Cylinder::local_normal_at(const TJRayTracer::Point &local_point) {
  return Vector(local_point.x, 0 , local_point.z);
}

std::shared_ptr<TJRayTracer::Cylinder> TJRayTracer::Cylinder::Glass_cylinder() {
  auto cylinder = std::make_shared<Cylinder>();
  cylinder->SetTransform(TF::identity());
  cylinder->material->transparency = 1.0;
  cylinder->material->refractive_index = 1.5;
  return cylinder;
}

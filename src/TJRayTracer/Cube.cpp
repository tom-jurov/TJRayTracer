#include "Cube.h"
#include "Equal.h"
TJRayTracer::Cube::Cube() : BaseObject() {}
TJRayTracer::Cube::Cube(
    const TJRayTracer::MatrixXd<double, 4, 4> &transform)
    : BaseObject(transform) {}
TJRayTracer::Cube::~Cube() noexcept {}

std::vector<TJRayTracer::Intersection>
TJRayTracer::Cube::local_intersect(const Ray &local_ray) {
    auto xt = this->check_axis(local_ray.GetOrigin().x, local_ray.GetDirection().x);
    auto yt = this->check_axis(local_ray.GetOrigin().y, local_ray.GetDirection().y);
    auto zt = this->check_axis(local_ray.GetOrigin().z, local_ray.GetDirection().z);
    
    double tmin = std::max({xt[0], yt[0], zt[0]});
    double tmax = std::min({xt[1], yt[1], zt[1]});

    if (tmin > tmax)
    {
        return {};
    }

    return {Intersection(tmin, std::make_shared<Cube>(*this)), Intersection(tmax, std::make_shared<Cube>(*this))};   
}

TJRayTracer::Vector
TJRayTracer::Cube::local_normal_at(const TJRayTracer::Point &local_point) {
    double maxc = std::max({fabs(local_point.x), fabs(local_point.y), fabs(local_point.z)});

    if (equal(maxc, fabs(local_point.x)))
    {
        return Vector(local_point.x, 0, 0);
    }
    else if (equal(maxc, fabs(local_point.y)))
    {
        return Vector(0, local_point.y, 0);
    }

    return Vector(0, 0, local_point.z);
}

std::vector<double> TJRayTracer::Cube::check_axis(double origin, double direction)
{
    double tmin_numerator = (-1 - origin);
    double tmax_numerator = (1 - origin);
    double tmin = 0;
    double tmax = 0;

    if (fabs(direction) >= EPSILON)
    {
        tmin = tmin_numerator / direction;
        tmax = tmax_numerator / direction;        
    }
    else
    {
        tmin = tmin_numerator * INFINITY;
        tmax = tmax_numerator * INFINITY;
    }

    if (tmin > tmax)
    {
        std::swap(tmin, tmax);
    }
    return {tmin, tmax};
}

std::shared_ptr<TJRayTracer::Cube> TJRayTracer::Cube::Glass_cube() {
  auto cube = std::make_shared<Cube>();
  cube->SetTransform(TF::identity());
  cube->material->transparency = 1.0;
  cube->material->refractive_index = 1.5;
  return cube;
}

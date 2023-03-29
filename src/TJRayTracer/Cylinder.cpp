#include "Cylinder.h"
#include "Equal.h"
TJRayTracer::Cylinder::Cylinder() : BaseObject(),_minimum(-INFINITY), _maximum(INFINITY), _closed(false) {}
TJRayTracer::Cylinder::Cylinder(
    const TJRayTracer::Matrix4d &transform)
    : BaseObject(transform) {}
TJRayTracer::Cylinder::~Cylinder() noexcept {}

std::vector<TJRayTracer::Intersection>
TJRayTracer::Cylinder::local_intersect(const Ray &local_ray) {
    double a = pow(local_ray.GetDirection().x(), 2) + pow(local_ray.GetDirection().z(), 2);
    std::vector<Intersection> xs;
    if(!(equal(a,0)))
    {

        double b = 2 * local_ray.GetOrigin().x() * local_ray.GetDirection().x() +
                2 * local_ray.GetOrigin().z() * local_ray.GetDirection().z();
        double c = pow(local_ray.GetOrigin().x(), 2)  + pow(local_ray.GetOrigin().z(), 2) - 1;

        double disc = b * b - 4 * a * c;

        if (disc < 0)
        {
            return {};
        }

        double t0 = (-b - sqrt(disc)) / (2 * a);
        double t1 = (-b + sqrt(disc)) / (2 * a);
        if (t0 > t1)
        {
            std::swap(t0, t1);
        }

        double y0 = local_ray.GetOrigin().y() + t0 * local_ray.GetDirection().y();
        if (_minimum < y0 && y0 < _maximum)
        {
            xs.push_back(Intersection(t0, std::make_shared<Cylinder>(*this)));
        }

        double y1 = local_ray.GetOrigin().y() + t1 * local_ray.GetDirection().y();
        if (_minimum < y1 && y1 < _maximum)
        {
            xs.push_back(Intersection(t1, std::make_shared<Cylinder>(*this)));
        }
    }
    this->intersect_caps(local_ray, xs);
    return xs;
}

TJRayTracer::Vector4d
TJRayTracer::Cylinder::local_normal_at(const TJRayTracer::Vector4d &local_point) {
    double dist = local_point.x() * local_point.x() + local_point.z() * local_point.z();
    if (dist < 1 && local_point.y() >= (_maximum - EPSILON))
    {
        return Vector4d(0, 1, 0, 0);
    }
    else if (dist < 1 && local_point.y() <= (_minimum + EPSILON))
    {
        return Vector4d(0, -1, 0, 0);
    }
    else 
    {
        return Vector4d(local_point.x(), 0 , local_point.z(), 0);
    }
}

std::shared_ptr<TJRayTracer::Cylinder> TJRayTracer::Cylinder::Glass_cylinder() {
  auto cylinder = std::make_shared<Cylinder>();
  cylinder->SetTransform(TF::Identity());
  cylinder->material->transparency = 1.0;
  cylinder->material->refractive_index = 1.5;
  return cylinder;
}

void TJRayTracer::Cylinder::SetMaximum(double maximum)
{
    _maximum = maximum;
}

void TJRayTracer::Cylinder::SetMinimum(double minimum)
{
    _minimum = minimum;
}

double TJRayTracer::Cylinder::GetMaximum() const
{
    return _maximum;
}

double TJRayTracer::Cylinder::GetMinimum() const
{
    return _minimum;
}

bool TJRayTracer::Cylinder::IsClosed() const
{
    return _closed;
}

void TJRayTracer::Cylinder::SetClosed(bool closed)
{
    _closed = closed;
}

bool TJRayTracer::Cylinder::check_cap(const Ray &ray, double t)
{
    double x = ray.GetOrigin().x() + t * ray.GetDirection().x();
    double z = ray.GetOrigin().z() + t * ray.GetDirection().z();

    return (x * x + z * z) <= 1;
}

void TJRayTracer::Cylinder::intersect_caps(const Ray &ray, std::vector<Intersection> &xs)
{
    if ((!_closed) || equal(ray.GetDirection().y(), 0))
        return;

    double t = (_minimum - ray.GetOrigin().y()) / ray.GetDirection().y();
    if (this->check_cap(ray, t))
    {
        xs.push_back(Intersection(t, std::make_shared<Cylinder>(*this)));
    }  

    t =  (_maximum - ray.GetOrigin().y()) / ray.GetDirection().y();
    if (this->check_cap(ray, t))
    {
        xs.push_back(Intersection(t, std::make_shared<Cylinder>(*this)));
    }
}

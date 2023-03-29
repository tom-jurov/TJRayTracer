#include "Cones.h"
#include "Equal.h"
TJRayTracer::Cones::Cones() : BaseObject(),_minimum(-INFINITY), _maximum(INFINITY), _closed(false) {}
TJRayTracer::Cones::Cones(
    const TJRayTracer::Matrix4d &transform)
    : BaseObject(transform) {}
TJRayTracer::Cones::~Cones() noexcept {}

std::vector<TJRayTracer::Intersection>
TJRayTracer::Cones::local_intersect(const Ray &local_ray) {
    double a = pow(local_ray.GetDirection().x(), 2) - pow(local_ray.GetDirection().y(), 2) + pow(local_ray.GetDirection().z(), 2);
    double b = 2 * local_ray.GetOrigin().x() * local_ray.GetDirection().x() -
            2 * local_ray.GetOrigin().y() * local_ray.GetDirection().y() +
            2 * local_ray.GetOrigin().z() * local_ray.GetDirection().z();
    double c = pow(local_ray.GetOrigin().x(), 2)  - pow(local_ray.GetOrigin().y(), 2) + pow(local_ray.GetOrigin().z(), 2);
    std::vector<Intersection> xs;
    if (equal(a,0) && !equal(b,0))
    {
        double t = -c / (2*b);
        xs.push_back(Intersection(t, std::make_shared<Cones>(*this)));
    }
    else if(!((equal(a,0)) && (equal(b,0))))
    {
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
            xs.push_back(Intersection(t0, std::make_shared<Cones>(*this)));
        }

        double y1 = local_ray.GetOrigin().y() + t1 * local_ray.GetDirection().y();
        if (_minimum < y1 && y1 < _maximum)
        {
            xs.push_back(Intersection(t1, std::make_shared<Cones>(*this)));
        }
    }
    this->intersect_caps(local_ray, xs);
    return xs;
}

TJRayTracer::Vector4d
TJRayTracer::Cones::local_normal_at(const TJRayTracer::Vector4d &local_point) {
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
        double y = sqrt(local_point.y() * local_point.y() + local_point.z() * local_point.z());
        if (local_point.y() > 0)
        {
            y = -y;
        }
        return Vector4d(local_point.x(), y , local_point.z(), 0);
    }
}

std::shared_ptr<TJRayTracer::Cones> TJRayTracer::Cones::Glass_cones() {
  auto cones = std::make_shared<Cones>();
  cones->SetTransform(TF::Identity());
  cones->material->transparency = 1.0;
  cones->material->refractive_index = 1.5;
  return cones;
}

void TJRayTracer::Cones::SetMaximum(double maximum)
{
    _maximum = maximum;
}

void TJRayTracer::Cones::SetMinimum(double minimum)
{
    _minimum = minimum;
}

double TJRayTracer::Cones::GetMaximum() const
{
    return _maximum;
}

double TJRayTracer::Cones::GetMinimum() const
{
    return _minimum;
}

bool TJRayTracer::Cones::IsClosed() const
{
    return _closed;
}

void TJRayTracer::Cones::SetClosed(bool closed)
{
    _closed = closed;
}

bool TJRayTracer::Cones::check_cap(const Ray &ray, double t)
{
    double x = ray.GetOrigin().x + t * ray.GetDirection().x;
    double z = ray.GetOrigin().z + t * ray.GetDirection().z;

    if (x * x + z * z <= fabs(_minimum) || x * x + z * z <= fabs(_maximum))
    {
        return true;
    }
    return false;
}

void TJRayTracer::Cones::intersect_caps(const Ray &ray, std::vector<Intersection> &xs)
{
    if ((!_closed) || equal(ray.GetDirection().y, 0))
        return;

    double t = (_minimum - ray.GetOrigin().y) / ray.GetDirection().y;
    if (this->check_cap(ray, t))
    {
        xs.push_back(Intersection(t, std::make_shared<Cones>(*this)));
    }  

    t =  (_maximum - ray.GetOrigin().y) / ray.GetDirection().y;
    if (this->check_cap(ray, t))
    {
        xs.push_back(Intersection(t, std::make_shared<Cones>(*this)));
    }
}


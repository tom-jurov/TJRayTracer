//
// Created by tomas on 3. 2. 2023.
//

#include "Ray.h"

TJRayTracer::Ray::Ray() : _origin(Point(0,0,0)), _direction(Vector(0,0,0)){}
TJRayTracer::Ray::Ray(const Point &origin, const Vector &direction) : _origin(origin), _direction(direction){}

const TJRayTracer::Point& TJRayTracer::Ray::GetOrigin() const
{
    return _origin;
}
const TJRayTracer::Vector& TJRayTracer::Ray::GetDirection() const
{
    return _direction;
}

TJRayTracer::Point TJRayTracer::Ray::position(double t) const
{
    return _origin + t*_direction;
}

TJRayTracer::Ray TJRayTracer::Ray::transform(const TJRayTracer::MatrixXd<double, 4, 4> &tf) const{
    TJRayTracer::Ray result;
    result.SetOrigin(tf*this->GetOrigin());
    result.SetDirection(tf*this->GetDirection());
    return result;
}

void TJRayTracer::Ray::SetOrigin(const TJRayTracer::Point &p) {
    _origin = p;
}

void TJRayTracer::Ray::SetDirection(const TJRayTracer::Vector &v) {
    _direction = v;
}

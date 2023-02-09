//
// Created by tomas on 5. 2. 2023.
//

#include "PointLight.h"
#include <cmath>
TJRayTracer::PointLight::PointLight(const Point &position, const Color &intensity) : _intensity(intensity), _position(position)
{

}
void TJRayTracer::PointLight::SetPosition(const Point &position)
{
    _position = position;
}
void TJRayTracer::PointLight::SetIntensity(const Color &intensity)
{
    _intensity = intensity;
}

const TJRayTracer::Point& TJRayTracer::PointLight::GetPosition() const
{
    return _position;
}

const TJRayTracer::Color& TJRayTracer::PointLight::GetIntensity() const
{
    return _intensity;
}

TJRayTracer::Color TJRayTracer::PointLight::lighting(const Material &m, const TJRayTracer::PointLight &light,
                                                     const TJRayTracer::Point &position,
                                                     const TJRayTracer::Vector &eyev,
                                                     const TJRayTracer::Vector &normalv) {

    auto effectiveColor = m.color*light.GetIntensity();
    auto lightv = (light.GetPosition()-position).normalize();
    auto ambient = effectiveColor*m.ambient;
    auto light_dot_normal = Vector::dot(lightv,normalv);
    Color diffuse;
    Color specular;
    Vector reflectv;
    double reflect_dot_eye = 0;
    if(light_dot_normal<0)
    {
        diffuse = Color(0,0,0);
        specular = Color(0,0,0);
    }
    else {
        diffuse = effectiveColor * m.diffuse * light_dot_normal;
        reflectv = Vector::reflect(-lightv, normalv);
        reflect_dot_eye = Vector::dot(reflectv, eyev);
        if (reflect_dot_eye <= 0) {
            specular = Color(0, 0, 0);
        } else {
            double factor = pow(reflect_dot_eye, m.shininess);
            specular = light.GetIntensity() * m.specular * factor;
        }
    }
    return ambient+diffuse+specular;
}

bool TJRayTracer::operator==(const TJRayTracer::PointLight &lhs, const TJRayTracer::PointLight &rhs) {
    return (lhs.GetIntensity() == rhs.GetIntensity()) && (lhs.GetPosition() == rhs.GetPosition());
}


//
// Created by tomas on 9. 2. 2023.
//
#include "World.h"
#include "Equal.h"
#include "Sphere.h"
#include <algorithm>
void TJRayTracer::World::default_world() {
  TJRayTracer::PointLight light(Vector4d(-10, 10, -10, 1), Color(1, 1, 1));
  std::unique_ptr<BaseObject> s1 = std::make_unique<TJRayTracer::Sphere>();
  s1->material = std::make_shared<Material>(Color(0.8, 1.0, 0.6), 0.1, 0.7, 0.2,
                                            200, nullptr, 0.0, 0.0, 1.0);
  std::unique_ptr<BaseObject> s2 =
      std::make_unique<TJRayTracer::Sphere>(TF::scaling(0.5, 0.5, 0.5));
  objects.clear();
  light_sources.clear();
  objects.emplace_back(std::move(s1));
  objects.emplace_back(std::move(s2));
  light_sources.emplace_back(std::move(light));
}

std::vector<TJRayTracer::Intersection>
TJRayTracer::World::intersect_world(const TJRayTracer::Ray &ray) {
  std::vector<TJRayTracer::Intersection> result;
  for (auto &object : objects) {
    auto temp = object->intersect(ray);
    result.insert(std::end(result), std::make_move_iterator(std::begin(temp)),
                  std::make_move_iterator(std::end(temp)));
  }
  sort(result.begin(), result.end(),
       [](const Intersection &lhs, const Intersection &rhs) -> bool {
         return lhs.t < rhs.t;
       });

  return result;
}

TJRayTracer::Color
TJRayTracer::World::shade_hit(const TJRayTracer::Comps &comps,
                              unsigned int remaining) {
  TJRayTracer::Color surface;
  TJRayTracer::Color reflected;
  TJRayTracer::Color refracted;
  for (auto &light : light_sources) {
    bool shadowed = this->is_shadowed(comps.over_point);
    surface =
        surface + TJRayTracer::PointLight::lighting(
                      comps.object->material, comps.object, light,
                      comps.over_point, comps.eyev, comps.normalv, shadowed);
    reflected = this->reflected_color(comps, remaining);
    refracted = this->refracted_color(comps, remaining);
    auto material = comps.object->material;
    if (material->reflective > 0 && material->transparency > 0) {
      double reflectance = Comps::schlick(comps);
      return surface + reflected * reflectance + refracted * (1 - reflectance);
    } else {
      return surface + reflected + refracted;
    }
  }
}

TJRayTracer::Color TJRayTracer::World::color_at(const TJRayTracer::Ray &ray,
                                                unsigned int remaining) {
  auto intersections = this->intersect_world(ray);
  if (intersections.size() != 0) {
    for (auto &intersection : intersections) {
      if (intersection.t >= 0) {
        auto comps =
            Comps::prepare_computations(intersection, ray, intersections);
        return this->shade_hit(comps, remaining);
      }
    }
  }
  return Color(0, 0, 0);
}

bool TJRayTracer::World::is_shadowed(const Vector4d &point) {
  auto v = this->light_sources[0].GetPosition() - point;
  double distance = v.norm();
  Vector4d direction = v.normalized();
  Ray ray(point, direction);
  auto intersections = this->intersect_world(ray);
  auto h = BaseObject::hit(intersections);
  if ((h.object != nullptr) && (h.t < distance)) {
    return true;
  }
  return false;
}

TJRayTracer::Color TJRayTracer::World::reflected_color(const Comps &comps,
                                                       unsigned int remaining) {
  if (equal(comps.object->material->reflective, 0) || (remaining <= 0)) {
    return Color(0, 0, 0);
  }

  Ray reflect_ray = Ray(comps.over_point, comps.reflectv);
  Color color = this->color_at(reflect_ray, remaining - 1);
  return (color * comps.object->material->reflective);
}

TJRayTracer::Color
TJRayTracer::World::refracted_color(const TJRayTracer::Comps &comps,
                                    unsigned int remaining) {
  if (equal(comps.object->material->transparency, 0) || (remaining <= 0)) {
    return Color(0, 0, 0);
  }
  double n_ratio = comps.n1 / comps.n2;
  double cos_i = comps.eyev.dot(comps.normalv);
  double sin2_t = n_ratio * n_ratio * (1 - cos_i * cos_i);
  if (sin2_t > 1) {
    return Color(0, 0, 0);
  }
  double cos_t = sqrt(1.0 - sin2_t);
  Vector4d direction =
      comps.normalv * (n_ratio * cos_i - cos_t) - comps.eyev * n_ratio;
  Ray refract_ray(comps.under_point, direction);
  return this->color_at(refract_ray, remaining - 1) *
         comps.object->material->transparency;
}

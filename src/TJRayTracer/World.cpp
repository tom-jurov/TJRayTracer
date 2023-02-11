//
// Created by tomas on 9. 2. 2023.
//
#include "World.h"
#include "Sphere.h"
void TJRayTracer::World::default_world() {
  TJRayTracer::PointLight light(Point(-10, 10, -10), Color(1, 1, 1));
  std::unique_ptr<BaseObject> s1 = std::make_unique<TJRayTracer::Sphere>();
  s1->material = std::make_shared<Material>(Color(0.8, 1.0, 0.6), 0.1, 0.7, 0.2,
                                            200, nullptr);
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
TJRayTracer::World::shade_hit(const TJRayTracer::Comps &comps) {
  TJRayTracer::Color color;
  for (auto &light : light_sources) {
    bool shadowed = this->is_shadowed(comps.over_point);
    color = color + TJRayTracer::PointLight::lighting(
                        comps.object->material, comps.object, light,
                        comps.over_point, comps.eyev, comps.normalv, shadowed);
  }
  return color;
}

TJRayTracer::Color TJRayTracer::World::color_at(const TJRayTracer::Ray &ray) {
  auto intersections = this->intersect_world(ray);
  if (intersections.size() != 0) {
    for (auto &intersection : intersections) {
      if (intersection.t >= 0) {
        auto comps = Comps::prepare_computations(intersection, ray);
        return this->shade_hit(comps);
      }
    }
  }
  return Color(0, 0, 0);
}

bool TJRayTracer::World::is_shadowed(const Point &point) {
  auto v = this->light_sources[0].GetPosition() - point;
  double distance = Vector::magnitude(v);
  Vector direction = v.normalize();
  Ray ray(point, direction);
  auto intersections = this->intersect_world(ray);
  auto h = BaseObject::hit(intersections);
  if ((h.object != nullptr) && (h.t < distance)) {
    return true;
  }
  return false;
}

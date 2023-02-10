#ifndef TJRAYTRACER_WORLD_H
#define TJRAYTRACER_WORLD_H
#include "BaseObject.h"
#include "Comps.h"
#include "PointLight.h"
#include "memory"
#include <vector>
namespace TJRayTracer {
class World {
public:
  World() = default;
  void default_world();
  World(double);
  ~World() = default;
  World(World &&) = default;
  World &operator=(World &&) = default;
  World(const World &) = default;
  World &operator=(const World &) = default;

public:
  [[nodiscard]] std::vector<Intersection> intersect_world(const Ray &ray);
  TJRayTracer::Color shade_hit(const Comps &comps);
  TJRayTracer::Color color_at(const Ray &ray);
  bool is_shadowed(const Point &point);

public:
  std::vector<std::shared_ptr<BaseObject>> objects;
  std::vector<PointLight> light_sources;
};
} // namespace TJRayTracer

#endif
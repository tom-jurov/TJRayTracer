//
// Created by tomas on 9. 2. 2023.
//

#ifndef TJRAYTRACER_COMPS_H
#define TJRAYTRACER_COMPS_H
#include "BaseObject.h"
namespace TJRayTracer {
class Comps {
public:
  double t;
  std::shared_ptr<BaseObject> object;
  Point point;
  Point over_point;
  Point under_point;
  Vector eyev;
  Vector normalv;
  bool inside;
  Vector reflectv;
  double n1;
  double n2;

public:
  static TJRayTracer::Comps
  prepare_computations(const TJRayTracer::Intersection &intersection,
                       const TJRayTracer::Ray &ray,
                       std::vector<Intersection> intersections = {});
  static double schlick(const Comps &comps);

public:
  Comps() = default;
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_COMPS_H

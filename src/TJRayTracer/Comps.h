//
// Created by tomas on 9. 2. 2023.
//

#ifndef TJRAYTRACER_COMPS_H
#define TJRAYTRACER_COMPS_H
#include "BaseObject.h"
#include "Point.h"
#include "Vector.h"
namespace TJRayTracer {
class Comps {
public:
  double t;
  BaseObject *object;
  Point point;
  Point over_point;
  Vector eyev;
  Vector normalv;
  bool inside;

public:
  static TJRayTracer::Comps
  prepare_computations(const TJRayTracer::Intersection &intersection,
                       const TJRayTracer::Ray &ray);

public:
  Comps() = default;
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_COMPS_H

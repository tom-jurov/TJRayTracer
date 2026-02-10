//
// Created by tomas on 9. 2. 2023.
//

#ifndef TJRAYTRACER_COMPS_H
#define TJRAYTRACER_COMPS_H
#include "TJRayTracerGlobal.h"
#include "BaseObject.h"
namespace TJRayTracer {
class TJRAYTRACER_API Comps {
public:
  double t;
  std::shared_ptr<BaseObject> object;
  Vector4d point;
  Vector4d over_point;
  Vector4d under_point;
  Vector4d eyev;
  Vector4d normalv;
  bool inside;
  Vector4d reflectv;
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

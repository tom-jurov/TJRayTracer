//
// Created by tomas on 9. 2. 2023.
//

#include "Comps.h"
#include "Equal.h"
#include <algorithm>
TJRayTracer::Comps TJRayTracer::Comps::prepare_computations(
    const TJRayTracer::Intersection &intersection, const TJRayTracer::Ray &ray,
    std::vector<TJRayTracer::Intersection> intersections) {
  if (intersections.size() == 0) {
    intersections.push_back(intersection);
  }
  TJRayTracer::Comps result;
  result.t = intersection.t;
  result.object = intersection.object;
  result.point = ray.position(result.t);
  result.eyev = ray.GetDirection();
  result.eyev = -result.eyev;
  result.normalv = result.object->normal_at(result.point);
  if (Vector::dot(result.normalv, result.eyev) < 0) {
    result.inside = true;
    result.normalv = -result.normalv;
  } else {
    result.inside = false;
  }
  result.over_point = result.point + result.normalv * EPSILON;
  result.under_point = result.point - result.normalv * EPSILON;
  result.reflectv = Vector::reflect(ray.GetDirection(), result.normalv);

  std::vector<std::shared_ptr<BaseObject>> containers;
  for (auto &inter : intersections) {
    if (inter == intersection) {
      if (containers.size() == 0) {
        result.n1 = 1.0;
      } else {
        result.n1 = containers.back()->material->refractive_index;
      }
    }
    bool flag = true;
    for (auto it = containers.begin(); it != containers.end(); ++it) {
      if (*it == inter.object) {
        containers.erase(it);
        flag = false;
        break;
      }
    }
    if (flag) {
      containers.push_back(inter.object);
    }
    if (inter == intersection) {
      if (containers.size() == 0) {
        result.n2 = 1.0;
      } else {
        result.n2 = containers.back()->material->refractive_index;
      }
    }
  }

  return result;
}

double TJRayTracer::Comps::schlick(const Comps &comps) {
  double cos = Vector::dot(comps.eyev, comps.normalv);

  if (comps.n1 > comps.n2) {
    double n = comps.n1 / comps.n2;
    double sin2_t = n * n * (1.0 - cos * cos);
    if (sin2_t > 1.0) {
      return 1.0;
    }
    double cos_t = sqrt(1.0 - sin2_t);
    cos = cos_t;
  }
  double r0 = pow(((comps.n1 - comps.n2) / (comps.n1 + comps.n2)), 2);
  return r0 + (1 - r0) * pow((1 - cos), 5);
}

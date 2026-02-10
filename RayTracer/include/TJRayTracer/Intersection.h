//
// Created by tomas on 4. 2. 2023.
//

#ifndef TJRAYTRACER_INTERSECTION_H
#define TJRAYTRACER_INTERSECTION_H
#include "TJRayTracerGlobal.h"
#include "BaseObject.h"
#include <functional>
#include <memory>
#include <stdarg.h>
#include <vector>
namespace TJRayTracer {
class BaseObject;
class TJRAYTRACER_API Intersection {
public:
  double t;
  std::shared_ptr<BaseObject> object;
  Intersection(double _t, std::shared_ptr<TJRayTracer::BaseObject> _object);
  friend bool operator==(const Intersection &lhs, const Intersection &rhs);
  friend bool operator!=(const Intersection &lhs, const Intersection &rhs);

  template <class... Ts>
  static std::vector<Intersection> intersections(Ts... inputs) {
    std::vector<Intersection> result;
    result = {inputs...};
    sort(result.begin(), result.end(),
         [](const Intersection &lhs, const Intersection &rhs) -> bool {
           return lhs.t < rhs.t;
         });
    return result;
  }
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_INTERSECTION_H

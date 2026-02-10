//
// Created by tomas on 4. 2. 2023.
//

#include "TJRayTracer/Intersection.h"
#include "TJRayTracer/Equal.h"
TJRayTracer::Intersection::Intersection(
    double _t, std::shared_ptr<TJRayTracer::BaseObject> _object)
    : t(_t), object(_object) {}

namespace TJRayTracer {
bool operator==(const Intersection &lhs, const Intersection &rhs) {
  if ((lhs.object == rhs.object) && equal(lhs.t, rhs.t)) {
    return true;
  }
  return false;
}
bool operator!=(const Intersection &lhs, const Intersection &rhs) {
  if (!(lhs == rhs))
    return true;
  return false;
}
} // namespace TJRayTracer

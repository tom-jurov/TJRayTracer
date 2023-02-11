//
// Created by tomas on 11. 2. 2023.
//

#include "BasePattern.h"
TJRayTracer::BasePattern::BasePattern(const Color &first_color,
                                      const Color &second_color)
    : a(first_color), b(second_color), _transform(TF::identity()) {}

void TJRayTracer::BasePattern::SetTransform(
    const TJRayTracer::MatrixXd<double, 4, 4> &transform) {
  _transform = transform;
}

TJRayTracer::MatrixXd<double, 4, 4>
TJRayTracer::BasePattern::GetTransform() const {
  return _transform;
}

TJRayTracer::BasePattern::BasePattern()
    : a(Color(1, 1, 1)), b(Color(0, 0, 0)), _transform(TF::identity()) {}

TJRayTracer::Color TJRayTracer::BasePattern::pattern_at_object(
    const std::shared_ptr<BaseObject> &object,
    const TJRayTracer::Point &world_point) {
  Point object_point = object->GetTransform().inverse() * world_point;
  Point pattern_point = this->_transform.inverse() * object_point;
  return this->pattern_at(pattern_point);
}

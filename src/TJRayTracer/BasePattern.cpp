//
// Created by tomas on 11. 2. 2023.
//

#include "BasePattern.h"
TJRayTracer::BasePattern::BasePattern(const Color &first_color,
                                      const Color &second_color)
    : a(first_color), b(second_color), _transform(TF::Identity()) {}

void TJRayTracer::BasePattern::SetTransform(
    const TJRayTracer::Matrix4d &transform) {
  _transform = transform;
}

TJRayTracer::Matrix4d
TJRayTracer::BasePattern::GetTransform() const {
  return _transform;
}

TJRayTracer::BasePattern::BasePattern()
    : a(Color(1, 1, 1)), b(Color(0, 0, 0)), _transform(TF::Identity()) {}

TJRayTracer::Color TJRayTracer::BasePattern::pattern_at_object(
    const std::shared_ptr<BaseObject> &object,
    const TJRayTracer::Vector4d &world_point) {
  Vector4d object_point = object->GetTransform().inverse() * world_point;
  Vector4d pattern_point = this->_transform.inverse() * object_point;
  return this->pattern_at(pattern_point);
}

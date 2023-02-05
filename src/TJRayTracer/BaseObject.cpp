//
// Created by tomas on 4. 2. 2023.
//

#include "BaseObject.h"
TJRayTracer::BaseObject::BaseObject() : _transform(TJRayTracer::TF::identity()){}
TJRayTracer::BaseObject::BaseObject(const TJRayTracer::MatrixXd<double, 4, 4> &transform) : _transform(transform){

}
TJRayTracer::BaseObject::~BaseObject() {}
std::vector<TJRayTracer::Intersection> TJRayTracer::BaseObject::intersect(const TJRayTracer::Ray &ray) {
    return {};
}

TJRayTracer::Intersection TJRayTracer::BaseObject::hit(const std::vector<TJRayTracer::Intersection>& intersections) {
    std::vector<TJRayTracer::Intersection> positiveHits;
    for(auto &v : intersections)
    {
        if(v.t >= 0)
        {
            return v;
        }
    }
    return Intersection(-1, nullptr);
}

void TJRayTracer::BaseObject::SetTransform(const TJRayTracer::MatrixXd<double, 4, 4> &transform) {
    _transform = transform;
}

TJRayTracer::MatrixXd<double, 4, 4> TJRayTracer::BaseObject::GetTransform() const{
    return _transform;
}

TJRayTracer::Vector TJRayTracer::BaseObject::normal_at(const TJRayTracer::Point &p) {
    return {0,0,0};
}

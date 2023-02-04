//
// Created by tomas on 4. 2. 2023.
//

#ifndef TJRAYTRACER_BASEOBJECT_H
#define TJRAYTRACER_BASEOBJECT_H
#include <vector>
#include "Intersection.h"
#include "Ray.h"
#include "TF.h"
#include "MatrixXd.h"
namespace TJRayTracer {
    class Intersection;
    class BaseObject {
    public:
        BaseObject();
        BaseObject(const TJRayTracer::MatrixXd<double,4,4> &transform);
        virtual ~BaseObject();
        void SetTransform(const TJRayTracer::MatrixXd<double,4,4>& transform);
        TJRayTracer::MatrixXd<double,4,4> GetTransform() const;
        [[nodiscard]] virtual std::vector<Intersection> intersect(const Ray& ray);
        [[nodiscard]] Intersection hit(const std::vector<Intersection> &intersections);
    private:
        TJRayTracer::MatrixXd<double,4,4> _transform;
    };
}
#endif //TJRAYTRACER_BASEOBJECT_H

//
// Created by tomas on 9. 2. 2023.
//

#include "Comps.h"

TJRayTracer::Comps TJRayTracer::Comps::prepare_computations(const TJRayTracer::Intersection& intersection,const TJRayTracer::Ray& ray)
{
    TJRayTracer::Comps result;
    result.t = intersection.t;
    result.object = intersection.object;
    result.point = ray.position(result.t);
    result.eyev = ray.GetDirection();
    result.eyev = -result.eyev;
    result.normalv = result.object->normal_at(result.point);
    if (Vector::dot(result.normalv, result.eyev) < 0)
    {
        result.inside = true;
        result.normalv = -result.normalv;
    }
    else
    {
        result.inside = false;
    }

    return result;
}

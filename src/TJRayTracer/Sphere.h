//
// Created by tomas on 3. 2. 2023.
//

#ifndef TJRAYTRACER_SPHERE_H
#define TJRAYTRACER_SPHERE_H
#include "Ray.h"
#include "Vector.h"
#include <cmath>
#include "BaseObject.h"
namespace TJRayTracer{
    class Sphere : public BaseObject{
    public:
        Sphere();
        Sphere(const MatrixXd<double,4,4>& transform);
        ~Sphere();
        bool intersections(const Ray& ray);
        [[nodiscard]] std::vector<Intersection> intersect(const Ray& ray);
    };
}


#endif //TJRAYTRACER_SPHERE_H

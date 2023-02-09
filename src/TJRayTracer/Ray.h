//
// Created by tomas on 3. 2. 2023.
//

#ifndef TJRAYTRACER_RAY_H
#define TJRAYTRACER_RAY_H
#include "Point.h"
#include "Vector.h"
#include "MatrixXd.h"
namespace TJRayTracer {
    class Ray {
    public:
        Ray();
        Ray(const Point& origin, const Vector& direction);
        Ray(const Ray&) = default;
        Ray(Ray&& )= default;
        Ray& operator=(const Ray& )= default;
        Ray& operator=(Ray&& )= default;
        const Point& GetOrigin() const;
        const Vector& GetDirection() const;
        void SetOrigin(const Point& p);
        void SetDirection(const Vector& v);
        Point position(double t) const;
        Ray transform(const MatrixXd<double,4,4>& tf) const;
        ~Ray() = default;

    private:
        Point _origin;
        Vector _direction;
    };
}


#endif //TJRAYTRACER_RAY_H

//
// Created by tomas on 9. 2. 2023.
//

#ifndef TJRAYTRACER_CAMERA_H
#define TJRAYTRACER_CAMERA_H
#include "MatrixXd.h"
#include "TF.h"
#include "Ray.h"
#include "Canvas.h"
#include "World.h"
namespace TJRayTracer {
    class Camera {
    public:
        Camera() = default;
        Camera(const int& hsize, const int& vsize, const double& fov);
        Ray ray_for_pixel(int px,int py);
        Canvas render(TJRayTracer::World& world);
        ~Camera() = default;
    public:
        int hsize;
        int vsize;
        double fov;
        MatrixXd<double,4,4> tf = TF::identity();
        double pixel_size;
        double half_width;
        double half_height;
    };
}


#endif //TJRAYTRACER_CAMERA_H

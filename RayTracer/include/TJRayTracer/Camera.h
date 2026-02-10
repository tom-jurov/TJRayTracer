//
// Created by tomas on 9. 2. 2023.
//

#ifndef TJRAYTRACER_CAMERA_H
#define TJRAYTRACER_CAMERA_H
#include "TJRayTracerGlobal.h"
#include "Canvas.h"
#include "Ray.h"
#include "TF.h"
#include "World.h"
namespace TJRayTracer {
class TJRAYTRACER_API Camera {
public:
  Camera() = default;
  Camera(const int &hsize, const int &vsize, const double &fov);
  Ray ray_for_pixel(int px, int py);
  Canvas render(TJRayTracer::World &world);
  ~Camera() = default;

public:
  int hsize;
  int vsize;
  double fov;
  Matrix4d tf = TF::Identity();
  double pixel_size;
  double half_width;
  double half_height;
};
} // namespace TJRayTracer

#endif // TJRAYTRACER_CAMERA_H

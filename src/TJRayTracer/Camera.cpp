//
// Created by tomas on 9. 2. 2023.
//

#include "Camera.h"
TJRayTracer::Camera::Camera(const int &hsize, const int &vsize,
                            const double &fov)
    : hsize(hsize), vsize(vsize), fov(fov) {
  auto half_view = tan(fov / 2);
  double aspect = (double)hsize / vsize;
  if (aspect >= 1) {
    half_width = half_view;
    half_height = half_view / aspect;
  } else {
    half_width = half_view * aspect;
    half_height = half_view;
  }
  pixel_size = half_width * 2 / hsize;
}

TJRayTracer::Ray TJRayTracer::Camera::ray_for_pixel(int px, int py) {
  double xoffset = (px + 0.5) * pixel_size;
  double yoffset = (py + 0.5) * pixel_size;
  double world_x = half_width - xoffset;
  double world_y = half_height - yoffset;

  TJRayTracer::Point pixel = tf.inverse() * Point(world_x, world_y, -1);
  TJRayTracer::Point origin = tf.inverse() * Point(0, 0, 0);
  TJRayTracer::Vector direction = (pixel - origin).normalize();
  return TJRayTracer::Ray(origin, direction);
}

TJRayTracer::Canvas TJRayTracer::Camera::render(TJRayTracer::World &world) {
  auto canvas = TJRayTracer::Canvas(hsize, vsize);

  for (std::size_t y = 0; y < vsize; ++y) {
    for (std::size_t x = 0; x < hsize; ++x) {
      TJRayTracer::Ray ray = this->ray_for_pixel(x, y);
      TJRayTracer::Color color = world.color_at(ray, 2);
      canvas.SetPixelColor(x, y, color);
    }
  }
  return canvas;
}

//
// Created by tomas on 3. 2. 2023.
//

#include "TJRayTracer/TF.h"
TJRayTracer::TF::TF() : _transform(Eigen::Matrix4d::Identity()){}

TJRayTracer::Matrix4d TJRayTracer::TF::GetTransform() const {
  return _transform;
}

void TJRayTracer::TF::operator=(
    const TJRayTracer::Matrix4d &other) {
  _transform = other;
}

TJRayTracer::Matrix4d
TJRayTracer::TF::translation(double x, double y, double z) {
  TJRayTracer::Matrix4d result = Eigen::Matrix4d::Identity();
  result(0, 3) = x;
  result(1, 3) = y;
  result(2, 3) = z;
  return result;
}

TJRayTracer::Matrix4d TJRayTracer::TF::scaling(double x, double y,
                                                             double z) {
  TJRayTracer::Matrix4d result = Eigen::Matrix4d::Identity();
  result(0, 0) = x;
  result(1, 1) = y;
  result(2, 2) = z;
  return result;
}

TJRayTracer::Matrix4d TJRayTracer::TF::rotation_x(double angle) {
  TJRayTracer::Matrix4d result = Eigen::Matrix4d::Identity();
  result(1, 1) = cos(angle);
  result(1, 2) = -sin(angle);
  result(2, 1) = sin(angle);
  result(2, 2) = cos(angle);
  return result;
}

TJRayTracer::Matrix4d TJRayTracer::TF::rotation_y(double angle) {
  TJRayTracer::Matrix4d result = Eigen::Matrix4d::Identity();
  result(0, 0) = cos(angle);
  result(0, 2) = sin(angle);
  result(2, 0) = -sin(angle);
  result(2, 2) = cos(angle);
  return result;
}

TJRayTracer::Matrix4d TJRayTracer::TF::rotation_z(double angle) {
  TJRayTracer::Matrix4d result = Eigen::Matrix4d::Identity();
  result(0, 0) = cos(angle);
  result(0, 1) = -sin(angle);
  result(1, 0) = sin(angle);
  result(1, 1) = cos(angle);
  return result;
}

TJRayTracer::Matrix4d
TJRayTracer::TF::shearing(double x_y, double x_z, double y_x, double y_z,
                          double z_x, double z_y) {
  TJRayTracer::Matrix4d result = Eigen::Matrix4d::Identity();
  result(0, 1) = x_y;
  result(0, 2) = x_z;
  result(1, 0) = y_x;
  result(1, 2) = y_z;
  result(2, 0) = z_x;
  result(2, 1) = z_y;
  return result;
}

TJRayTracer::Matrix4d TJRayTracer::TF::Identity() {
  TJRayTracer::Matrix4d result = Eigen::Matrix4d::Identity();
  return result;
}

TJRayTracer::Matrix4d
TJRayTracer::TF::view_transform(const TJRayTracer::Vector4d &from,
                                const TJRayTracer::Vector4d &to,
                                const TJRayTracer::Vector4d &up) {
  Vector4d forward = (to - from).normalized();
  Vector4d upn = up.normalized();
  Eigen::Vector3d upn_3(upn.x(), upn.y(), upn.z());
  Eigen::Vector3d forward_3(forward.x(), forward.y(), forward.z());
  Eigen::Vector3d left = forward_3.cross(upn_3);
  Eigen::Vector3d true_up = left.cross(forward_3);
  auto orientation = TF::Identity();
  orientation(0, 0) = left.x();
  orientation(0, 1) = left.y();
  orientation(0, 2) = left.z();
  orientation(1, 0) = true_up.x();
  orientation(1, 1) = true_up.y();
  orientation(1, 2) = true_up.z();
  orientation(2, 0) = -forward.x();
  orientation(2, 1) = -forward.y();
  orientation(2, 2) = -forward.z();
  return orientation * TF::translation(-from.x(), -from.y(), -from.z());
}

//
// Created by tomas on 3. 2. 2023.
//

#include "TF.h"
TJRayTracer::TF::TF()
{
    _transform.identity();
}

TJRayTracer::MatrixXd<double, 4, 4> TJRayTracer::TF::GetTransform() const{
    return _transform;
}

void TJRayTracer::TF::operator=(const TJRayTracer::MatrixXd<double, 4, 4> &other) {
    _transform = other;
}

TJRayTracer::MatrixXd<double, 4, 4> TJRayTracer::TF::translation(double x, double y, double z) {
    TJRayTracer::MatrixXd<double, 4, 4> result;
    result.identity();
    result(0,3) = x;
    result(1,3) = y;
    result(2,3) = z;
    return result;
}

TJRayTracer::MatrixXd<double, 4, 4> TJRayTracer::TF::scaling(double x, double y, double z) {
    TJRayTracer::MatrixXd<double, 4, 4> result;
    result.identity();
    result(0,0) = x;
    result(1,1) = y;
    result(2,2) = z;
    return result;
}

TJRayTracer::MatrixXd<double, 4, 4> TJRayTracer::TF::rotation_x(double angle) {
    TJRayTracer::MatrixXd<double, 4, 4> result;
    result.identity();
    result(1,1) = cos(angle);
    result(1,2) = -sin(angle);
    result(2,1) = sin(angle);
    result(2,2) = cos(angle);
    return result;
}

TJRayTracer::MatrixXd<double, 4, 4> TJRayTracer::TF::rotation_y(double angle) {
    TJRayTracer::MatrixXd<double, 4, 4> result;
    result.identity();
    result(0,0) = cos(angle);
    result(0,2) = sin(angle);
    result(2,0) = -sin(angle);
    result(2,2) = cos(angle);
    return result;
}

TJRayTracer::MatrixXd<double, 4, 4> TJRayTracer::TF::rotation_z(double angle) {
    TJRayTracer::MatrixXd<double, 4, 4> result;
    result.identity();
    result(0,0) = cos(angle);
    result(0,1) = -sin(angle);
    result(1,0) = sin(angle);
    result(1,1) = cos(angle);
    return result;
}

TJRayTracer::MatrixXd<double, 4, 4>
TJRayTracer::TF::shearing(double x_y, double x_z, double y_x, double y_z, double z_x, double z_y) {
    TJRayTracer::MatrixXd<double, 4, 4> result;
    result.identity();
    result(0,1) = x_y;
    result(0,2) = x_z;
    result(1,0) = y_x;
    result(1,2) = y_z;
    result(2,0) = z_x;
    result(2,1) = z_y;
    return result;
}

TJRayTracer::MatrixXd<double, 4, 4> TJRayTracer::TF::identity() {
    TJRayTracer::MatrixXd<double, 4, 4> result;
    result.identity();
    return result;
}

TJRayTracer::MatrixXd<double, 4, 4>
TJRayTracer::TF::view_transform(const TJRayTracer::Point &from, const TJRayTracer::Point &to,
                                const TJRayTracer::Vector &up) {
    auto forward = (to-from).normalize();
    auto upn = up.normalize();
    auto left = Vector::cross(forward, upn);
    auto true_up = Vector::cross(left,forward);
    auto orientation = TF::identity();
    orientation(0,0) = left.x;
    orientation(0,1) = left.y;
    orientation(0,2) = left.z;
    orientation(1,0) = true_up.x;
    orientation(1,1) = true_up.y;
    orientation(1,2) = true_up.z;
    orientation(2,0) = -forward.x;
    orientation(2,1) = -forward.y;
    orientation(2,2) = -forward.z;
    return orientation*TF::translation(-from.x, -from.y, -from.z);
}

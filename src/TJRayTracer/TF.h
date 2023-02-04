//
// Created by tomas on 3. 2. 2023.
//

#ifndef TJRAYTRACER_TF_H
#define TJRAYTRACER_TF_H
#include "MatrixXd.h"
#include <cmath>
namespace TJRayTracer {
    class TF {
    public:
        TF();
        static MatrixXd<double,4,4> identity();
        static MatrixXd<double,4,4> translation(double x, double y, double z);
        static MatrixXd<double,4,4> scaling(double x, double y, double z);
        static MatrixXd<double,4,4> rotation_x(double angle);
        static MatrixXd<double,4,4> rotation_y(double angle);
        static MatrixXd<double,4,4> rotation_z(double angle);
        static MatrixXd<double,4,4> shearing(double x_y, double x_z, double y_x, double y_z, double z_x, double z_y);
        [[nodiscard]] MatrixXd<double,4,4> GetTransform() const;
        void operator= (const MatrixXd<double,4,4>& other);
        ~TF() = default;
    private:
        MatrixXd<double,4,4> _transform;
    };
}


#endif //TJRAYTRACER_TF_H

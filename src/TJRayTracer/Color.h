//
// Created by tomas on 1. 2. 2023.
//

#ifndef TJRAYTRACER_COLOR_H
#define TJRAYTRACER_COLOR_H

namespace TJRayTracer {
    class Color{
    public:
        double red,green,blue;
    public:
        Color();
        Color(double red, double green, double blue);
        ~Color();

    public:
        friend bool operator==(const Color &lhs,const Color &rhs);
        friend Color operator+(const Color &lhs, const Color &rhs);
        friend Color operator-(const Color &lhs, const Color &rhs);
        friend Color operator*(const double& scalar, const Color &rhs);
        friend Color operator*(const Color &lhs, const Color &rhs);
        Color operator*(const double& scalar) const;

    };
}


#endif //TJRAYTRACER_COLOR_H

//
// Created by tomas on 5. 2. 2023.
//

#ifndef TJRAYTRACER_MATERIAL_H
#define TJRAYTRACER_MATERIAL_H
#include "Color.h"
namespace TJRayTracer {
    class Material {
    public:
        Material();
        Material(const Color& color,double ambient, double diffuse, double specular, double shininess);
        ~Material() = default;
        Material(Material&&) = default;
        Material& operator=(Material &&) = default;
        Material(const Material&) = default;
        Material& operator=(const Material&) = default;
        friend bool operator==(const Material& lhs, const Material& rhs);
    public:
        Color color;
        double ambient;
        double diffuse;
        double specular;
        double shininess;
    };
}


#endif //TJRAYTRACER_MATERIAL_H

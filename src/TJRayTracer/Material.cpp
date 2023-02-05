//
// Created by tomas on 5. 2. 2023.
//

#include "Material.h"
TJRayTracer::Material::Material(const Color& color, double ambient, double diffuse, double specular, double shininess) : color(color), ambient(ambient),\
                                                                                                    diffuse(diffuse), specular(specular), shininess(shininess){}

TJRayTracer::Material::Material() {
    color = Color(1,1,1);
    ambient = 0.1;
    diffuse = 0.9;
    specular = 0.9;
    shininess = 200.0;
}
namespace TJRayTracer {
    bool operator==(const TJRayTracer::Material &lhs, const TJRayTracer::Material &rhs) {
        if (lhs.color == rhs.color && lhs.ambient == rhs.ambient && lhs.diffuse == rhs.diffuse
            && lhs.specular == rhs.specular && lhs.shininess == rhs.shininess)
            return true;
        return false;
    }
}
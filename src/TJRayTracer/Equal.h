//
// Created by tomas on 29. 1. 2023.
//

#ifndef TJRAYTRACER_EQUAL_H
#define TJRAYTRACER_EQUAL_H
#include <cmath>
#define EPSILON 0.00001

bool equal(const double &a, const double &b)
{
    return (std::abs(a - b) < EPSILON);
}

#endif //TJRAYTRACER_EQUAL_H

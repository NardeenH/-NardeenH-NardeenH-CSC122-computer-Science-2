#pragma once

#include <string>

#ifndef SPHERE_H
#define SPHERE_H

class Sphere {
private:
    double radius;

public:
    Sphere(double r = 0) : radius(r) {}

    double getRadius() const {
        return radius;
    }

    void setRadius(double r) {
        radius = r;
    }

    double surfaceArea() const {
        return 4 * 3.14 * radius * radius;
    }

    double volume() const {
        return (4.0 / 3.0) * 3.14 * radius * radius * radius;
    }
};
#endif
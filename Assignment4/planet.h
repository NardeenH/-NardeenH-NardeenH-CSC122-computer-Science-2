#pragma once

#include <iostream>
#include <string>
#include "sphere.h"


#ifndef PLANET_H

#define PLANET_H


class Planet : public Sphere {
private:
    double mass;

public:
    Planet(double r = 0, double m = 0) : Sphere(r), mass(m) {}
    double getMass() const {
        return mass;
    }

    void setMass(double m) {
        mass = m;
    }

    double density() const {
        double v = volume();
        return (v == 0) ? 0 : mass / v;
    }

    double gravity() const {
        const double G = 6.67430e-11; // Gravitational constant
        double r = getRadius();
        return (r == 0) ? 0 : (G * mass) / (r * r);
    }
};

#endif
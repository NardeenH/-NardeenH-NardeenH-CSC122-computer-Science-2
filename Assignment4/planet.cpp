//Assignment 6 planet

#include <iostream>
#include <cmath>
#include "sphere.h"
#include "planet.h"

using namespace std;

int main() {
    double radius, mass;

    cout << "Enter the radius of the planet: ";
    cin >> radius;

   cout << "Enter the mass of the planet: ";
    cin >> mass;

    Planet planet(radius, mass);

    cout << "\n \x1b[4mSurface area of planet\x1b[0m: " << planet.surfaceArea() << " sq m" << endl;
    cout << "\n \x1b[4mDensity of planet\x1b[0m: " << planet.density() << " kg" << endl;
    cout << "\n \x1b[4mAcceleration due to gravity at surface\x1b[0m: " << planet.gravity() << " m/s^2" << endl;

    return 0;
}

//In this assignment you will be creating a base class and derived class to perform some basic calculations for planets.

//For the base class, create a class for a sphere.  This class will store the radius of the sphere (private).  It will need to have an accessor and mutator for the radius.  You class should also have a constructor and functions to calculate surface area and volume.

//our planet class will be derived from your sphere class.  It should add mass as a private member (with mutator and accessor) along with a constructor and functions to calculate density and acceleration due to gravity at the surface.  Functions for input and display are optional.

//Using this class, write a program that will prompt the user for the radius and mass of a planet.  Your program will display the surface area, density and acceleration due to gravity at the surface.

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

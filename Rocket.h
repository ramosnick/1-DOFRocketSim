#ifndef ROCKET_H
#define ROCKET_H

#include <cmath>

class Rocket {
    private:
    double maxThrust; //Read in upon construction
    double fuel; //Read in
    double mass; //Read in initial mass, mass of fuel is added to initial mass.

    public:
    double height; //Starts at 0, updated by physics engine
    double currentThrust;

    //Constructor
    Rocket(double maxThrust, double fuel, double initialMass);

    //Helpers
    double getMaxThrust();
    double getFuel();
    double getMass();

    /*All functions below this point may be moved to Control Unit class havent decided yet...*/

    void updateFuel(double dt, double rate); //Will be called by physics engine with the time between calls being dt
    void updateMass(double massLost); //Will only be called in updateFuel with newly updated fuel as argument

    void updateCurrentThrust();

};

#endif
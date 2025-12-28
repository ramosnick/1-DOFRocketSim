#ifndef ROCKET_H
#define ROCKET_H

#include <cmath>
#include <fstream>

class Rocket {
    private:
    double maxThrust; //Read in upon construction
    double fuel; //Read in
    double mass; //Read in initial mass, mass of fuel is added to initial mass. (Mass is in kg)

    public:
    float time;
    double height; //Starts at 0, updated by physics engine
    double currentThrust;
    double currentAccelerration;
    double currentVelocity;

    //Constructor
    Rocket(double maxThrust, double fuel, double initialMass);

    //Helpers
    double getMaxThrust();
    double getFuel();
    double getMass();
    double getHeight();
    double getVelocity();

    //Flight Data Fxns//
    void saveData(std::ofstream outputFile);

    /*All functions below this point may be moved to Control Unit class havent decided yet...*/

    void updateFuel(double dt, double rate); //Will be called by physics engine with the time between calls being dt
    void updateMass(double massLost); //Will only be called in updateFuel with newly updated fuel as argument
    void updateVelocity(double newVelocity);
    void updateHeight(double newHeight);

    void updateCurrentThrust();

};

#endif
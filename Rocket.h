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
    double currentThrust;
    double currentYForce;
    double currentAcceleration;
    double currentVelocity;
    double height; //Starts at 0, updated by physics engine

    //Constructor
    Rocket(double maxThrust, double fuel, double initialMass);

    //Helpers
    double getMaxThrust();
    double getCurrentThrust();
    double getCurrentYForce();
    double getFuel();
    double getMass();
    double getVelocity();
    double getHeight();

    //Flight Data Fxns//
    void saveData(std::ofstream& outputFile);

    /*All functions below this point may be moved to Control Unit class havent decided yet...*/

    void updateCurrentThrust(double newThrust); //Sets thrust output
    void updateCurrentYForce(double newYForce); //Stores current Y force in rocket object
    void updateCurrentAcc(double newAcc);
    void updateCurrentVelocity(double newVelocity);
    void updateFuel(double dt, double rate); //Will be called by physics engine with the time between calls being dt
    void updateMass(double massLost); //Will only be called in updateFuel with newly updated fuel as argument
    void updateVelocity(double newVelocity);
    void updateHeight(double newHeight);

    void updateCurrentThrust();

};

#endif
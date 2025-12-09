#include "Rocket.h"

Rocket::Rocket(double maxThrust, double fuel, double initialMass) {

    this->maxThrust = maxThrust;
    this->fuel = fuel;
    this->mass = initialMass + fuel;

}

double Rocket::getMaxThrust() {
    return this->maxThrust;
}

double Rocket::getFuel() {
    return this->fuel;
}

double Rocket::getMass() {
    return this->mass;
}

void Rocket::updateFuel(double dt, double rate) {
    //This has potential to be really cool if I can learn the math required to burn fuel based off of thrust...
    double fuelLost = this->fuel - dt*rate;
    updateMass(fuelLost);
}

void Rocket::updateMass(double massLost) {
    this->mass -= massLost;
}
 #include "Rocket.h"

Rocket::Rocket(double maxThrust, double fuel, double initialMass) {

    this->maxThrust = maxThrust;
    this->fuel = fuel;
    this->mass = initialMass + fuel;

}

double Rocket::getMaxThrust() {
    return this->maxThrust;
}

double Rocket::getCurrentThrust() {
    return this->currentThrust;
}

double Rocket::getCurrentYForce() {
    return this->currentYForce;
}

double Rocket::getFuel() {
    return this->fuel;
}

double Rocket::getMass() {
    return this->mass;
}

double Rocket::getHeight() {
    return this->height;
}

double Rocket::getVelocity() {
    return this->currentVelocity;
}

//Flight Data Fxns//
/*Output file will be opened in main, columns will be read in outside of control loop, data will be read in 
within saveData function, file will be closed in main, outside of control loop*/
void Rocket::saveData(std::ofstream& outputFile) {

    outputFile << this->time << ','
               << getHeight() << ','
               << getVelocity() << ','
               << this->currentAcceleration << ','
               << this->currentThrust << ','
               << getMass() <<std::endl;
    /*Will update to either access all variable directly or will create getters for all of them to use instead,
    haven't decided which to do yet, leaning towards direct access for speed...*/

}

void Rocket::updateCurrentThrust(double newThrust) {
    this->currentThrust = newThrust;
}

void Rocket::updateCurrentYForce(double newYForce) {
    this->currentYForce = newYForce;
}

void Rocket::updateCurrentAcc(double newAcc) {
    this->currentAcceleration = newAcc;
}

void Rocket::updateCurrentVelocity(double newVelocity) {
    this->currentVelocity = newVelocity;
}

void Rocket::updateFuel(double dt, double rate) {
    //This has potential to be really cool if I can learn the math required to burn fuel based off of throttle...
    double fuelLost = this->fuel - dt*rate;
    updateMass(fuelLost);
}

void Rocket::updateMass(double massLost) {
    this->mass -= massLost;
}

void Rocket::updateVelocity(double newVelocity) {
    this->currentVelocity += newVelocity;
}

void Rocket::updateHeight(double newHeight) {
    this->height = newHeight;
}
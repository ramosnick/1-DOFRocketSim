#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine() {}

void PhysicsEngine::incrementTime() {
    this->time += dt;
}

double PhysicsEngine::calculateForce(double currentThrust, Rocket rocket) {

    double downForce = rocket.getMass() * gravity;
    double upForce = rocket.getMaxThrust(); //Only using maxThrust for preliminary testing

    return upForce - downForce;

}

double PhysicsEngine::calcAcc(Rocket rocket, double currentYForce) {

    return currentYForce / rocket.getMass();

}

double PhysicsEngine::calcVelocity(Rocket rocket, double accelerration) {
    
    return rocket.getVelocity() + (accelerration * dt);

}

void PhysicsEngine::calcNewHeight(Rocket rocket, double currentYForce) {

    rocket.updateHeight(rocket.getHeight() + (rocket.getVelocity() * dt));

}
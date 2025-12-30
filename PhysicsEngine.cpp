#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine() {}

void PhysicsEngine::incrementTime() {
    this->time += dt;
}

double PhysicsEngine::calculateForce(Rocket& rocket) {

    double downForce = rocket.getMass() * gravity;
    double upForce = rocket.getCurrentThrust();

    rocket.updateCurrentYForce(upForce - downForce);
    return upForce - downForce;

}

double PhysicsEngine::calcAcc(Rocket& rocket) {

    double newAcc = rocket.getCurrentYForce() / rocket.getMass();
    rocket.updateCurrentAcc(newAcc);
    return newAcc;

}

double PhysicsEngine::calcVelocity(Rocket& rocket) {
    
    double newVelocity = rocket.getVelocity() + (rocket.currentAcceleration * dt);
    rocket.updateCurrentVelocity(newVelocity);
    return newVelocity;
}

void PhysicsEngine::calcNewHeight(Rocket& rocket) {

    double newHeight = rocket.getHeight() + (rocket.getVelocity() * dt);

    rocket.updateHeight(newHeight);

}
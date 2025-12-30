#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "Rocket.h"

class PhysicsEngine {

    public:
    float gravity = 9.8; //Newtons/kg
    float time = 0.000; //Seconds
    float dt = 0.001; //Seconds
    float drag; //Implement later //FIXME

    //Constructor
    PhysicsEngine();
    void incrementTime();
    double calculateForce(Rocket& rocket);
    double calcAcc(Rocket& rocket);
    double calcVelocity(Rocket& rocket);
    void calcNewHeight(Rocket& rocket); //Updates height variable in rocket object
    
};

#endif
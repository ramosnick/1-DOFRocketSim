#include "Rocket.h"
#include "PhysicsEngine.h"

int main() {
    Rocket rocket(7607000, 549000, 575200);
    PhysicsEngine physics{};

    std::ofstream outputFile;
    outputFile.open("RocketSimFlightData.csv");

     while(physics.time < 100) {

        rocket.updateCurrentThrust(rocket.getMaxThrust()); //Setting thrust to max thrust for now...

        physics.calculateForce(rocket);
        physics.calcAcc(rocket);
        physics.calcVelocity(rocket);
        physics.calcNewHeight(rocket);

        rocket.saveData(outputFile);

        physics.time += physics.dt;

    }
     outputFile.close();
     return 0;
}

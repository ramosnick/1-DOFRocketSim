#include "Rocket.h"
#include "PhysicsEngine.h"

int main() {
    Rocket rocket(7607000, 549000, 575200);
    PhysicsEngine physics{};

    std::ofstream outputFile;
    outputFile.open("RocketSimFlightData.csv");

     while(physics.time < 100) {

     }
     outputFile.close();
}
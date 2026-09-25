#include "RobotController.h"

#include <iostream>

int main() {
    // These defaults mirror config/robot_config.yaml for this small example.
    RobotConfig config;
    RobotController controller(config);

    controller.printStatus();

    const double requestedSpeedMps = 0.40;
    const double obstacleDistanceM = 0.50;

    std::cout << "Motion request at " << requestedSpeedMps << " m/s: "
              << (controller.canMove(requestedSpeedMps, obstacleDistanceM)
                      ? "allowed"
                      : "blocked")
              << '\n';

    return 0;
}

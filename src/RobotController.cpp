#include "RobotController.h"

#include <iostream>
#include <utility>

RobotController::RobotController(RobotConfig config)
    : config_(std::move(config)) {}

void RobotController::printStatus() const {
    std::cout << "Robot: " << config_.name << '\n';
    std::cout << "Mode: " << config_.controlMode << '\n';
    std::cout << "Autonomous speed limit: "
              << config_.maxAutonomousSpeedMps << " m/s\n";
    std::cout << "Emergency stop: "
              << (config_.emergencyStopEnabled ? "enabled" : "disabled") << '\n';
}

bool RobotController::canMove(double requestedSpeedMps,
                              double obstacleDistanceM) const {
    if (config_.obstacleDetectionEnabled &&
        obstacleDistanceM < config_.minimumClearanceM) {
        return false;
    }

    const double speedLimit = config_.controlMode == "manual"
        ? config_.maxManualSpeedMps
        : config_.maxAutonomousSpeedMps;

    return requestedSpeedMps >= 0.0 && requestedSpeedMps <= speedLimit;
}

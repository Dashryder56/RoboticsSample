#pragma once

#include <string>

struct RobotConfig {
    std::string name = "warehouse-bot";
    std::string controlMode = "autonomous";
    double maxAutonomousSpeedMps = 0.50;
    double maxManualSpeedMps = 0.25;
    bool emergencyStopEnabled = true;
    bool obstacleDetectionEnabled = true;
    double minimumClearanceM = 0.20;
};

class RobotController {
public:
    explicit RobotController(RobotConfig config);

    void printStatus() const;
    bool canMove(double requestedSpeedMps, double obstacleDistanceM) const;

private:
    RobotConfig config_;
};

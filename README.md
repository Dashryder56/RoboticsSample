# Tabletop Robot Controller

A small C++ reference controller and configuration project for simulated tabletop warehouse robots.

## Purpose

This repository demonstrates a lightweight robot control loop used to test autonomous behavior on a marked tabletop workspace. The controller loads motion and sensor limits from `config/robot_config.yaml` and reports the robot's current operating mode.

## Safety Configuration

Robot motion limits are defined in `config/robot_config.yaml`.

Autonomous operation is limited to 0.35 m/s.

The controller supports obstacle detection, minimum-clearance rules, and emergency-stop behavior.

## Configuration

- Autonomous operation is enabled by default.
- Manual control is limited to 0.25 m/s.
- Obstacle detection is enabled.
- Minimum obstacle clearance is 0.20 m.

## Build

A C++17 compiler is sufficient for this example:

```bash
g++ -std=c++17 -o robot_controller src/main.cpp src/RobotController.cpp
./robot_controller
```

This sample does not require external libraries.

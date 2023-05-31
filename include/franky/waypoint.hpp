#pragma once

#include <optional>

#include <Eigen/Geometry>

#include "franky/robot_pose.hpp"
#include "franky/types.hpp"
#include "franky/motion/reference_type.hpp"

namespace franky {

struct Waypoint {
  RobotPose robot_pose;
  ReferenceType reference_type{ReferenceType::Absolute};

  //! Dynamic Waypoint: Relative velocity factor
  double velocity_rel{1.0}, acceleration_rel{1.0}, jerk_rel{1.0};

  //! Dynamic Waypoint: Use maximal dynamics of the robot independent on other parameters
  bool max_dynamics{false};

  //! Dynamic Waypoint: Minimum time to get to next waypoint
  std::optional<double> minimum_time{std::nullopt};

  [[nodiscard]] RobotPose getTargetRobotPose(const RobotPose &old_robot_pose) const;
};

}  // namespace franky

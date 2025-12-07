#pragma once

#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <ros/ros.h>
#include <string>

class RobotInfo {
public:
  RobotInfo() = default;

  RobotInfo(ros::NodeHandle *node_handle, std::string &robot_description,
            std::string &serial_number, std::string &ip_address,
            std::string &firmware_version);

  virtual ~RobotInfo() = default;
  virtual void publish_data();

protected:
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;

  ros::NodeHandle *nh;
  ros::Publisher robot_info_pub;
};
#pragma once

#include "robot_info/robot_info_class.h"
#include <ros/ros.h>
#include <string>

class HydraulicSystemMonitor;

class AGVRobotInfo : public RobotInfo{
    public:
        AGVRobotInfo(ros::NodeHandle *node_handle, std::string &robot_description,
               std::string &serial_number, std::string &ip_address, std::string &firmware_version,
               std::string &maximum_payload);
        
        virtual ~AGVRobotInfo() = default;

        virtual void publish_data() override;
    private:
        std::string maximum_payload;

        //object of the class as member
        HydraulicSystemMonitor *hydraulic_monitor;
};
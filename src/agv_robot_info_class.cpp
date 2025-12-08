#include "robot_info/agv_robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "hydraulic_system_monitor.cpp"

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle,
                           std::string &robot_description,
                           std::string &serial_number, std::string &ip_address,
                           std::string &firmware_version,
                           std::string &maximum_payload)
    : RobotInfo(node_handle, robot_description, serial_number, ip_address,
                firmware_version),
      maximum_payload(maximum_payload)
    {
        // Values are hardcoded here to match the assignment
        hydraulic_monitor = new HydraulicSystemMonitor("45C", "100%", "250 bar");
        ROS_INFO("AGVRobotInfo object created");
}

void AGVRobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg;

  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number: " + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version: " + firmware_version;
  msg.data_field_05 = "maximum_payload: " + maximum_payload;

  msg.data_field_06 = "hydraulic_oil_temerature: " + hydraulic_monitor->getHydraulicOilTemperature();
  msg.data_field_07 = "hydraulic_oil_tank_fill_level: " + hydraulic_monitor->getHydraulicOilTankFillLevel();
  msg.data_field_08 = "hydraulic_oil_pressure: " + hydraulic_monitor->getHydraulicOilPressure();
  msg.data_field_09 = "";
  msg.data_field_10 = "";

  robot_info_pub.publish(msg);
  ROS_INFO_STREAM("AGVRobotInfo published");
}
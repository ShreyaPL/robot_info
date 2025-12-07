#include "robot_info/robot_info_class.h"


RobotInfo::RobotInfo(ros::NodeHandle *node_handle, std::string &robot_description, std::string &serial_number,
                    std::string &ip_address, std::string &firmware_version)
    : nh(node_handle),
    robot_description(robot_description),
    serial_number(serial_number),
    ip_address(ip_address),
    firmware_version(firmware_version)
{
  // Publisher on topic "robot_info" using RobotInfo10Fields message
  robot_info_pub =
      nh->advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);

  ROS_INFO("RobotInfo publisher created on topic 'robot_info'");
}

void RobotInfo::publish_data(){
    robotinfo_msgs::RobotInfo10Fields msg;

    msg.data_field_01 = "robot_description: " + robot_description;
    msg.data_field_02 = "serial_number: " + serial_number;
    msg.data_field_03 = "ip_address: " + ip_address;
    msg.data_field_04 = "firmware_version: " + firmware_version;
    msg.data_field_05 = "";
    msg.data_field_06 = "";
    msg.data_field_07 = "";
    msg.data_field_08 = "";
    msg.data_field_09 = "";
    msg.data_field_10 = "";

    robot_info_pub.publish(msg);
    ROS_INFO_STREAM("RobotInfo published");
}       


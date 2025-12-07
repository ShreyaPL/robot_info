#include "robot_info/agv_robot_info_class.h"
#include "ros/node_handle.h"
#include <ros/ros.h>

int main(int argc, char **argv){
    ros::init(argc, argv, "agv_robot_info_node");
    
    ros::NodeHandle node_handle;
    std::string rb_name = "Cooper100";
    std::string sn = "567A359";
    std::string ip = "169.54.5.180";
    std::string fv = "3.5.8";
    std::string mp = "100 Kg";
    
    AGVRobotInfo agv_info_obj(&node_handle, rb_name, sn, ip, fv, mp);

    // to publish data
    ros::Rate loop_rate(1.0);
    while (ros::ok()) {
        agv_info_obj.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
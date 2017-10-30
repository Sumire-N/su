#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
void scanCallback(const sensor_msgs::LaserScan::ConstPtr& msg){
  std::cout <<  "I heard:" << msg->ranges[540] << std::endl;
}
int main(int argc, char **argv){
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("scan", 1000, scanCallback);          
  ros::spin();
  return 0;              
}

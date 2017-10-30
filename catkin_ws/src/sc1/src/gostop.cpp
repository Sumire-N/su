#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h" 
double distance = 0;

void Callback(const sensor_msgs::LaserScan::ConstPtr& msg){
  distance = msg->ranges[540];
  std::cout << "I heard:" << distance << std::endl;
}

int main(int argc,char **argv){
  geometry_msgs::Twist msg; 
  ros::init(argc,argv,"sc1_listener");
  ros::NodeHandle n;
  ros::Subscriber sensor_sub =n.subscribe("scan", 1000, Callback);
  ros::Publisher sensor_pub = n.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity",1000);
  ros::Rate loop_rate(10);
  while(ros::ok()){
    if(distance<2){
      msg.linear.x = 0.0;
      msg.angular.z = 0.5;
      sensor_pub.publish(msg);
    }
    else{
      msg.linear.x = 0.3;
      msg.angular.z = 0.0;
      sensor_pub.publish(msg);
    } 
    loop_rate.sleep();//sleepの値考えていれよう！
  }
  ros::spin();
  return 0;
}

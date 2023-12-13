#include "ros/ros.h"
#include "std_msgs/String.h"
#include <ctime>

#include <sstream>

std_msgs::String str_var; 

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  str_var.data = msg->data; // save the data in the callback
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  std::stringstream ss;
  std::time_t result = std::time(nullptr);
  ss << msg->data.c_str()<<" Patryk Grys "<<std::asctime(std::localtime(&result));
  std_msgs::String msg_to_send;
  msg_to_send.data = ss.str();
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("RaptorOUT", 1000);
  while (chatter_pub.getNumSubscribers() < 1) {
    ros::WallDuration sleep_t(0.5);    
    sleep_t.sleep();
  }
  
  ROS_INFO("%s", msg_to_send.data.c_str());
  
  chatter_pub.publish(msg_to_send);
  	
  
  ros::spinOnce();
}

int main(int argc, char **argv)
{
  
  std::cout<<"Hello World!!!"<<std::endl;
  
  ros::init(argc, argv, "main");
  ros::NodeHandle n;
  
  ros::Subscriber sub = n.subscribe("RaptorIN", 1000, chatterCallback);

  
  ros::spin();

  return 0;
}

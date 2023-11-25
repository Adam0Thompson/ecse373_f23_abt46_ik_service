#include "ros/ros.h"
#include "ik_service/PoseIK.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ik_client");
  
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ik_service::PoseIK>("pose_ik");
  ik_service::PoseIK srv;
  if (client.call(srv))
  {
    ROS_INFO("Response...");
  else
  {
    ROS_ERROR("Failed to call service ik_service");
    return 1;
  }

  return 0;
}
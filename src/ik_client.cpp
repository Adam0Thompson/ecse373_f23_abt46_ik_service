#include "ros/ros.h"
#include "ik_service/PoseIK.h"
#include <cstdlib>
#include "geometry_msgs/Pose.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ik_client");
  
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ik_service::PoseIK>("pose_ik");
  ik_service::PoseIK pose_ik;
  geometry_msgs::Pose part_pose;

  part_pose.position.x = 0.100536;
  part_pose.position.y = 0.163939;
  part_pose.position.z = 0.082258;

  part_pose.orientation.x = 0;
  part_pose.orientation.y = 0;
  part_pose.orientation.z = 0;
  part_pose.orientation.w = 0;

  pose_ik.request.part_pose = part_pose;

  ROS_INFO_STREAM("Sent to service: " << pose_ik.request);

  if (client.call(pose_ik))
  {
    ROS_INFO("Response returned %i solutions", pose_ik.response.num_sols);
  }
  else
  {
    ROS_ERROR("Failed to call service ik_service");
    return 1;
  }

  return 0;
}
#include "ros/ros.h"
#include "ik_service/PoseIK.h"
#include "ur_kinematics/ur_kin.h"
#include "ik_service/JointSolutions.h"

bool pose_ik(ik_service::PoseIK::Request  &req, ik_service::PoseIK::Response &res){
  ROS_INFO("pose_ik was called");
  //res.num_sols = -1;
  //return true;

  // Process request into T matrix
  double T[4][4] = {{0.0, -1.0, 0.0, req.part_pose.position.x}, \
                    {0.0, 0.0, 1.0, req.part_pose.position.y}, \
                    {-1.0, 0.0, 0.0, req.part_pose.position.z}, \
                    {0.0, 0.0, 0.0, 1.0}};
  
  // Variable to store number of solutions
  int num_sol;

  // Variable to store up to 8 solutions for 6 joint angles
  float q_sols[8][6];

  // Perform inverse kinematics to find solution(s)
  num_sol = ur_kinematics::inverse(&T[0][0],(double *)&q_sols[0][0], 0.0);

  // Pass number of solutions into response, adn telegraph this info
  res.num_sols = num_sol;
  if (num_sol > 0){
    ROS_INFO("%i solutions found", num_sol);

    // Fill the joint_solutions in the response with the data from q_sols
    for (int sol = 0; sol < 8; sol++){
      for (int ja = 0; ja < 6; ja++){
        res.joint_solutions[sol].joint_angles[ja] = q_sols[sol][ja];
      }
    }

    return true;
  }
  else {
    ROS_WARN("No solutions found");
    return false;
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ik_srv");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("pose_ik", pose_ik);
  ROS_INFO("ik_service_node ready");
  ros::spin();

  return 0;
}

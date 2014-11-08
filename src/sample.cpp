//Copyright (c) 2014 Naohiro Hayshi and ROS JAPAN Users Group ALL Rights Reserved 
//Author Naohiro Hayashi 2014/11/07
#include "ros/ros.h"
#include <iostream>
#include <nextage_ros_seqplay_util/goPose.h>
#include <hrpsys_ros_bridge/OpenHRP_SequencePlayerService_waitInterpolation.h>
#include <hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setTargetPose.h>
#include <hrpsys_ros_bridge/OpenHRP_SequencePlayerService_waitInterpolationOfGroup.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_seqplay_utilclient");

  ROS_INFO("test_move");

  ros::NodeHandle n;
  
  //goInitial
  ros::ServiceClient initialclient = n.serviceClient<nextage_ros_seqplay_util::goPose>("/nextage_seqplay_util/goInitial");
  nextage_ros_seqplay_util::goPose initialsrv;
  initialsrv.request.tm =2.0;
  
  //waitInterpolation
  ros::ServiceClient waitclient = n.serviceClient<hrpsys_ros_bridge::OpenHRP_SequencePlayerService_waitInterpolation>("/SequencePlayerServiceROSBridge/waitInterpolation");
  hrpsys_ros_bridge::OpenHRP_SequencePlayerService_waitInterpolation waitsrv;
  
  //setTargetPoseRelative
  ros::ServiceClient targetclient = n.serviceClient<hrpsys_ros_bridge::OpenHRP_SequencePlayerService_setTargetPose>("/nextage_seqplay_util/setTargetPoseRelative");
  hrpsys_ros_bridge::OpenHRP_SequencePlayerService_setTargetPose targetsrv;
  targetsrv.request.name = "larm";
  targetsrv.request.xyz.resize(3);
  targetsrv.request.xyz[0] = 0.0;
  targetsrv.request.xyz[1] = 0.0;
  targetsrv.request.xyz[2] = 0.1;
  targetsrv.request.rpy.resize(3);
  targetsrv.request.rpy[0] = 0.0;
  targetsrv.request.rpy[1] = 0.0;
  targetsrv.request.rpy[2] = 0.0;
  targetsrv.request.tm = 2.0;
  
  //leftwaitInterpolation
  ros::ServiceClient leftwaitclient = n.serviceClient<hrpsys_ros_bridge::OpenHRP_SequencePlayerService_waitInterpolationOfGroup>("/SequencePlayerServiceROSBridge/waitInterpolationOfGroup");
  hrpsys_ros_bridge::OpenHRP_SequencePlayerService_waitInterpolationOfGroup leftwaitsrv;
  leftwaitsrv.request.gname = "larm";

  //goOffPose
  ros::ServiceClient gooffclient = n.serviceClient<nextage_ros_seqplay_util::goPose>("/nextage_seqplay_util/goOffPose");
  nextage_ros_seqplay_util::goPose gooffsrv;
  gooffsrv.request.tm =5.0;
  
//call service
  //initial pose
  std::cout << "initial" << std::endl;
  if (initialclient.call(initialsrv))
  {
    ROS_INFO("Success goInitial");
  }
  else
  {
    ROS_ERROR("Error goInitial");
  }
  //wait
  std::cout << "wait" << std::endl;
  if (waitclient.call(waitsrv))
  {
    ROS_INFO("Success wait");
  }
  else
  {
    ROS_ERROR("Error wait");
  }
  //move left hand
  std::cout << "target" << std::endl;
  if (targetclient.call(targetsrv))
  {
    ROS_INFO("Success target");
  }
  else
  {
    ROS_ERROR("Error target");
  }
  //wait
  std::cout << "leftwait" << std::endl;
  if (leftwaitclient.call(leftwaitsrv))
  {
    ROS_INFO("Success left wait");
  }
  else
  {
    ROS_ERROR("Error leftwait");
  }
  //go off pose
  std::cout << "gooff" << std::endl;
  if (gooffclient.call(gooffsrv))
  {
    ROS_INFO("Success gooff");
  }
  else
  {
    ROS_ERROR("Error gooff");
  }
  //~ 

  return 0;
}

-#!/bin/bash		
 -		
 -pwd		
ls		
cd ../../catkin_ws/src		
pwd		
ls		
env | grep CMAKE_PREFIX_PATH		
echo $CMAKE_PREFIX_PATH
catkin config --extend /opt/ros/indigo
catkin build
source devel/setup.bash
echo $CMAKE_PREFIX_PATH
ls		
cd /root/src/pluginlib_arrayutil_client		
pwd

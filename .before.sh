#!/bin/bash

pwd
ls
cd ../../catkin_ws/src
pwd
ls
env | grep CMAKE_PREFIX_PATH
sudo catkin install
ls
cd /root/src/pluginlib_arrayutil_client
pwd

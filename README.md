# Velodyne ROS Driver For Windows
This package allow you to connect to the Velodyne laserscanner with ROS Melodic on Windows like you would with the [ubuntu version of this package](https://github.com/ros-drivers/velodyne).

## 1. Downlaod and build
Open a CMD terminal
```
mkdir velodyne_ws
cd velodyne_ws
mkdir src
cd src
git clone https://github.com/Drone-Research-Lab/Velodyne-ROS-Windows.git
cd ..
catkin_make
```

## 2. Usage
This driver connects to velodyne laserscanner at ip: 192.168.1.10
```
cd devel
setup.bash
cd ..
roslaunch velodyne_pointcloud VLP16_points.launch
```
This should connect to the driver and publish the data on a topic "/velodyne"

#include <iostream>
#include <string>
#include <vector>

#include "ros/ros.h"
#include <sensor_msgs/PointCloud2.h>

#include <pcl_ros/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

typedef pcl::PointXYZI rgbpoint;
typedef pcl::PointCloud<pcl::PointXYZI> cloudrgb;
typedef cloudrgb::Ptr cloudptr;

cloudptr PC(new cloudrgb());

void cloud_cb(const sensor_msgs::PointCloud2ConstPtr& cloud) {

    std::cout << "hello" << std::endl;
    pcl::fromROSMsg(*cloud, *PC); //Now you can process this PC using the pcl functions

     int point_size = PC->size();
    std::cout << "Size of PCL cloud: " << point_size << std::endl;
}

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "velodyne_node");

    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/velodyne_points", 1, cloud_cb);

    ros::spin();



    return 0;
}
#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"

bool add(beginner_tutorials::AddTwoInts::Request &req,
	beginner_tutorials::AddTwoInts::Response &res){
	res.Sum = req.A + req.B;
	ROS_INFO("request: x=%ld, y=%ld", (long int)req.A, (long int)req.B);
	ROS_INFO("sending back response: [%ld]", (long int)res.Sum);
	return true;
}

int main(int argc, char **argv){
	ros::init(argc, argv, "add_two_ints_serverr");
	ros::NodeHandle n;

	ros::ServiceServer service= n.advertiseService("add_two_ints", add);
	ROS_INFO("Ready to add two ints.");
	ros::spin();

	return 0;
}
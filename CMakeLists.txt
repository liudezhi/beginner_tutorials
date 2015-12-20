cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  genmsg

  message_runtime
)

add_message_files(
  FILES
  Num.msg
)

add_service_files(
  FILES
  AddTwoInts.srv
)

generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES beginner_tutorials
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(talkerrr src/talker.cpp)
target_link_libraries(talkerrr ${catkin_LIBRARIES})
add_dependencies(talkerrr beginner_tutorials_generate_messages_cpp)

add_executable(listenerrr src/listener.cpp)
target_link_libraries(listenerrr ${catkin_LIBRARIES})
add_dependencies(listenerrr beginner_tutorials_generate_messages_cpp)


add_executable(add_two_ints_serverrr src/add_two_ints_server.cpp)
target_link_libraries(add_two_ints_serverrr ${catkin_LIBRARIES})
add_dependencies(add_two_ints_serverrr beginner_tutorials_gencpp)

add_executable(add_two_ints_clienttt src/add_two_ints_client.cpp)
target_link_libraries(add_two_ints_clienttt ${catkin_LIBRARIES})
add_dependencies(add_two_ints_clienttt beginner_tutorials_gencpp)
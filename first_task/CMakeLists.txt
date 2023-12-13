cmake_minimum_required(VERSION 3.0.2)
project(first_task)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)


add_message_files(
  FILES
  first.msg
)



catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES first_task
  CATKIN_DEPENDS message_runtime roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(main src/main.cpp)
target_link_libraries(main ${catkin_LIBRARIES})

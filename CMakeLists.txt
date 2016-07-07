cmake_minimum_required(VERSION 2.8.3)
project(apriltag)

set(CMAKE_C_FLAGS "-std=gnu99 -Wall -Wno-unused-parameter -Wno-unused-function -pthread -O4 ${CMAKE_C_FLAGS}")

# @todo this does NOT work, since it should set ${CMAKE_THREAD_LIBS_INIT}, but
# it does NOT!
#find_package(Threads REQUIRED)

find_package(catkin REQUIRED)

catkin_package(
  INCLUDE_DIRS . common
  LIBRARIES ${PROJECT_NAME} ${PROJECT_NAME}-common)

include_directories(
  .
  common
  ${catkin_INCLUDE_DIRS})

add_library(${PROJECT_NAME}-common
  common/getopt.c
  common/homography.c
  common/image_f32.c
  common/image_u32.c
  common/image_u8.c
  common/matd.c
  common/pnm.c
  common/string_util.c
  common/svd22.c
  common/time_util.c
  common/unionfind.c
  common/workerpool.c
  common/zarray.c
  common/zhash.c
  common/zmaxheap.c)
target_link_libraries(${PROJECT_NAME}-common pthread m)

add_library(${PROJECT_NAME}
  apriltag.c
  apriltag_quad_thresh.c
  g2d.c
  tag16h5.c
  tag25h9.c
  tag25h7.c
  tag36h10.c
  tag36artoolkit.c
  tag36h11.c)
target_link_libraries(${PROJECT_NAME}
  ${PROJECT_NAME}-common ${catkin_LIBRARIES})

add_executable(apriltag_demo apriltag_demo.c)
target_link_libraries(apriltag_demo ${PROJECT_NAME} ${catkin_LIBRARIES})

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}-common apriltag_demo
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

# Install the root and common headers:
# Note that we need to exclude the 'debian' folder (from bloom-release) to
# avoid an infinite recursion in the installation process.
# See https://cmake.org/cmake/help/v3.0/command/install.html
install(DIRECTORY ./
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN "debian" EXCLUDE)

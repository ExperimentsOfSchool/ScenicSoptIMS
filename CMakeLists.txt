cmake_minimum_required(VERSION 3.6)
project(ScenicSpotIMS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ScenicSpot.cpp ScenicSpot.h main.cpp Utilities.cpp Utilities.h ParkingLot.cpp ParkingLot.h Vehicle.cpp Vehicle.h)
add_executable(ScenicSpotIMS ${SOURCE_FILES})
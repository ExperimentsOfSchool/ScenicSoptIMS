cmake_minimum_required(VERSION 3.6)
project(ScenicSpotIMS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES MainView.cpp MainView.h main.cpp ScenicSpot.cpp ScenicSpot.h Functions.cpp Functions.h)
add_executable(ScenicSpotIMS ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.10)

project(vector_addtition_visualization)

find_package(PCL REQUIRED)

add_executable(vector_addtition_visualization main.cpp)

target_link_libraries(vector_addtition_visualization ${PCL_LIBRARIES})
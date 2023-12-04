cmake_minimum_required(VERSION 3.22)
project(tparser)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

add_library(${PROJECT_NAME} source/tparser.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
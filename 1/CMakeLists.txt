cmake_minimum_required(VERSION 3.22)
project(hw1)

option(BUILD_TEST BOOL OFF)

add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(lib_isEqual)

target_link_libraries(${PROJECT_NAME} isEqual)

if(BUILD_TEST)
	message("Enable testing")
	enable_testing()
endif()
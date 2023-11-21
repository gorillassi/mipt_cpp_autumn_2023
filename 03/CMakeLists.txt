cmake_minimum_required(VERSION 3.22)
project(03)

option(BUILD_TEST BOOL OFF)

add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(lib_allocator)

target_link_libraries(${PROJECT_NAME} lib_allocator)

 

if(BUILD_TEST)
	message("Enable testing")
	enable_testing()
endif()
cmake_minimum_required(VERSION 3.22)
project(lib_allocator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DRUN_TESTS)

add_library(${PROJECT_NAME} source/allocator.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  allocator_test
  source/allocator_test.cpp
)
target_link_libraries(
  allocator_test
  ${PROJECT_NAME}
  GTest::gtest_main
)
target_include_directories(allocator_test PUBLIC include)

include(GoogleTest)
gtest_discover_tests(allocator_test)
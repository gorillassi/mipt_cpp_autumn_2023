cmake_minimum_required(VERSION 3.22)
project(isEqual)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} source/isEqual.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  isEqual_test
  source/isEqual_test.cpp
)
target_link_libraries(
  isEqual_test
  ${PROJECT_NAME}
  GTest::gtest_main
)
target_include_directories(isEqual_test PUBLIC include)

include(GoogleTest)
gtest_discover_tests(isEqual_test)
cmake_minimum_required(VERSION 3.22)
project(libstemmer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} source/libstemmer.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  libstemmer_test
  source/libstemmer_test.cpp
)
target_link_libraries(
  libstemmer_test
  ${PROJECT_NAME}
  GTest::gtest_main
)
target_include_directories(libstemmer_test PUBLIC include)

include(GoogleTest)
gtest_discover_tests(libstemmer_test)
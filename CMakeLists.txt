cmake_minimum_required(VERSION 3.15)
project(MiniDB CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The disk manager library
add_library(minidb src/disk_manager.cpp)
target_include_directories(minidb PUBLIC include)

# The test executable
add_executable(disk_manager_test tests/disk_manager_test.cpp)
target_link_libraries(disk_manager_test PRIVATE minidb)
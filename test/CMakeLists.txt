cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

project(FileManagerTest)
enable_testing()
find_package(GTest CONFIG REQUIRED)

add_test(AllTestsInMain main)

add_executable(FileManagerTest FileManagerFile_test.cpp)
target_link_libraries(FileManagerTest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(FileManagerTest)

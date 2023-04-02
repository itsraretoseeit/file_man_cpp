cmake_minimum_required(VERSION 3.20)

project(FileManager)


include_directories(inc)
add_executable(FileManager src/main.cpp src/FileManagerFile.cpp)

set_property(TARGET FileManager PROPERTY CXX_STANDARD 17)

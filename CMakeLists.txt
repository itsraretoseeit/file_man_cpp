cmake_minimum_required(VERSION 3.20)

project(FileManager)

add_executable(FileManager src/main.cpp)
set_property(TARGET FileManager PROPERTY CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(example-app)

add_executable(example-app main.cpp)
set_property(TARGET example-app PROPERTY CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(example-app)

set(CMAKE_PREFIX_PATH "/home/heixiu/libtorch/libtorch")
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(example-app Read_file.cpp)
target_link_libraries(example-app "${TORCH_LIBRARIES}")
set_property(TARGET example-app PROPERTY CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(LibtorchExample)

find_package(Torch REQUIRED)

add_executable(main main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(main "${TORCH_LIBRARIES}")
set_property(TARGET main PROPERTY CXX_STANDARD 17)
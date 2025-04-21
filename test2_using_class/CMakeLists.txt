cmake_minimum_required(VERSION 3.20)
project(libtorch_example_2)

# 设置 LibTorch 根目录
set(CMAKE_PREFIX_PATH "/home/heixiu/libtorch/libtorch")
find_package(Torch REQUIRED)

# 定义可执行文件（先创建目标）
add_executable(example-app 
  main.cpp 
  src/myfunction.cpp
  src/myfunction2.cpp
)

# 添加 LibTorch 和自定义头文件目录
target_include_directories(example-app
  PRIVATE
    ${TORCH_INCLUDE_DIRS}          # LibTorch 头文件目录
    ${PROJECT_SOURCE_DIR}/include  # 自定义头文件目录
)

# 链接 LibTorch
target_link_libraries(example-app 
  ${TORCH_LIBRARIES}  # 或直接使用 torch::torch
)
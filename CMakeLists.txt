cmake_minimum_required(VERSION 3.10)
project(galaxy)

# Conan 集成
include(${CMAKE_SOURCE_DIR}/conan_toolchain.cmake) 

# 添加可执行文件
add_executable(galaxy main.cpp)

find_package(Crow REQUIRED)
# 链接 Crow 库和其他依赖
target_link_libraries(galaxy PRIVATE Crow::Crow)
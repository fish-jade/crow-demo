cmake_minimum_required(VERSION 3.10)
project(galaxy)

# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
endif()

# Conan 集成
include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake) 

# 添加可执行文件
add_executable(galaxy main.cpp)

find_package(Crow)
# 链接 Crow 库和其他依赖
target_link_libraries(galaxy PUBLIC Crow::Crow)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
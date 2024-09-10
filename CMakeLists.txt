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

# 定义资源目录
set(ASSETS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets")
set(ASSETS_DESTINATION_DIR "${CMAKE_CURRENT_BINARY_DIR}/assets")

# 创建自定义命令来复制资源
add_custom_command(
    OUTPUT ${ASSETS_DESTINATION_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${ASSETS_SOURCE_DIR}
    ${ASSETS_DESTINATION_DIR}
    DEPENDS ${ASSETS_SOURCE_DIR}
    COMMENT "Copying assets directory"
)

# 创建自定义目标
add_custom_target(copy_assets ALL DEPENDS ${ASSETS_DESTINATION_DIR})

# 添加可执行文件
add_executable(galaxy main.cpp)

add_dependencies(galaxy copy_assets)

find_package(Crow)

# 链接 Crow 库和其他依赖
target_link_libraries(galaxy PUBLIC Crow::Crow)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14) # C++14 交叉编译工具是6.4.0gcc 17部分支持但不稳定
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
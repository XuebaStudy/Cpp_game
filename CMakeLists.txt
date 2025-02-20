# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(main)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置强制使用静态库
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")

set(CMAKE_PREFIX_PATH "External/SFML-2.6.2/lib/cmake/SFML")
# 查找 SFML
find_package(SFML 2.6 REQUIRED COMPONENTS system window graphics)

# 添加可执行文件
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Creature.cpp
    src/Summoner.cpp
    src/Event.cpp
    src/Tools.cpp
    src/UserIO.cpp
    src/Mode.cpp
    src/Effect.cpp
)

# 添加头文件目录
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include/
    ${PROJECT_SOURCE_DIR}/include/battle
)

# 链接 SFML 动态库
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
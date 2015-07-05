cmake_minimum_required(VERSION 3.2)
project(sfml_gamedev)

include_directories(/usr/local/include/SFML)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

set(MY_LIB_LINK_LIBRARIES -lsfml-graphics -lsfml-audio -lsfml-network -lsfml-window -lsfml-system)

set(SOURCE_FILES main.cpp sprites.cpp sprites.h)
add_executable(game ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(game ${MY_LIB_LINK_LIBRARIES})
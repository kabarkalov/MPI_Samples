cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME_STR build_sample)
set(CMAKE_CXX_STANDARD 11)

project (${PROJECT_NAME_STR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/)

file(GLOB SRC_FILES 
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

add_executable(${PROJECT_NAME_STR} ${SRC_FILES})

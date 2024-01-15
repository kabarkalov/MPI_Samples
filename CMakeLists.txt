cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME_STR mpi_samples)
set(CMAKE_CXX_STANDARD 11)

set(OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/_bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIRECTORY})



project (${PROJECT_NAME_STR})

find_package(MPI REQUIRED)


file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/)
include_directories(SYSTEM ${MPI_INCLUDE_PATH})
#add_executable(${PROJECT_NAME_STR} ${SRC_FILES})
#target_link_libraries(${PROJECT_NAME_STR} ${MPI_C_LIBRARIES})


add_subdirectory(src)



#find_package(OpenMP)
#if (OPENMP_FOUND)
#    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#endif()

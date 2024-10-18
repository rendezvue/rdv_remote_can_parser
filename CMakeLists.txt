project(rdv_remote_can_parser)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#opencv
find_package(OpenCV REQUIRED)
include_directories( ${OPENCV_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR} )

#boost
find_package(Boost REQUIRED COMPONENTS system thread filesystem regex date_time program_options)
#find_package(Boost REQUIRED)
include_directories( ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} )
include_directories( ${Boost_LIBRARY_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ) 

message(CMAKE_CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

#src
set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)
FILE(GLOB SRC_SRC "${SRC_PATH}/*.cpp" ) 
include_directories(${SRC_PATH})

#Example src
set(EXAMPLE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/example)
FILE(GLOB EXAMPLE_SRC "${EXAMPLE_PATH}/*.cpp" ) 
include_directories(${EXAMPLE_PATH})

message(SRC_PATH="${SRC_PATH}")
message(EXAMPLE_PATH="${EXAMPLE_PATH}")

message(SRC_SRC="${SRC_SRC}")
message(EXAMPLE_SRC="${EXAMPLE_SRC}")


add_executable( rdv_remote_can_parser ${SRC_SRC} ${EXAMPLE_SRC} )

target_link_libraries(rdv_remote_can_parser ${OpenCV_LIBS})
target_link_libraries(rdv_remote_can_parser ${Boost_LIBRARIES})

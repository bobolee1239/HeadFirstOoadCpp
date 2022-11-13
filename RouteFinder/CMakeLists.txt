cmake_minimum_required(VERSION 3.10)

project(ROUTE_FINDER NONE)
enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(${CMAKE_CURRENT_LIST_DIR})
add_definitions(
    -DENABLE_DEBUG_LOG
    -DENABLE_INFORMATION_LOG
    -DENABLE_ERROR_LOG
    )

# add_library(RouteFinder
#     )

add_executable(SubwayTester
    Test/TestSubway.cpp 
    )
# target_link_libraries(RouteFinderTest
#     RouteFinder
#     )


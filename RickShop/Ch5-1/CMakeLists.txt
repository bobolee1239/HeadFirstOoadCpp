cmake_minimum_required(VERSION 3.10)

project(RICKS_GUITAR NONE)
enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_executable(FindGuitarTester
    FindGuitarTester.cpp 
    )


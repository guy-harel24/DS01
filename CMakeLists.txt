cmake_minimum_required(VERSION 3.27)
project(DataStructure01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DataStructure01
        AVL_Tree.h
        main.cpp
        Node.h)

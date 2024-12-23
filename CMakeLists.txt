cmake_minimum_required(VERSION 3.27)
project(DataStructure01)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(DataStructure01
        main.cpp
        Node.h
        AVL_Tree.h)

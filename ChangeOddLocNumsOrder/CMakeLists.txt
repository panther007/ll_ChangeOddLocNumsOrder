cmake_minimum_required(VERSION 3.10)
project(ChangeOddLocNumsOrder)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(ChangeOddLocNumsOrder
        ChangeOddLocNumsOrder.cpp
        ChangeOddLocNumsOrder.hpp
        Makefile SingleLinkedList.cpp SingleLinkedList.hpp)

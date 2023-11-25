cmake_minimum_required(VERSION 3.26)
project(Lab3_Encapsulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab3_Encapsulation main.cpp
        Wrapper.cpp
        Wrapper.h
        Engine.cpp
        Engine.h)

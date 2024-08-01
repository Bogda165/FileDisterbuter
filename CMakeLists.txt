cmake_minimum_required(VERSION 3.28)
project(file_type_script)

set(CMAKE_CXX_STANDARD 17)

add_executable(file_type_script main.cpp
        Core.cpp
        Core.h
        Constant.h)

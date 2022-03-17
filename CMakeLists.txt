cmake_minimum_required(VERSION 3.21)
project(c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(c
        1-4.h
        1-5.h
        1-6.h
        123.h
        3-5.h
        main.c)

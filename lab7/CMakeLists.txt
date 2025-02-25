cmake_minimum_required(VERSION 3.30)
project(cpsc_2311 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cpsc_2311
    driver.c
    functions.c
    functions.h)

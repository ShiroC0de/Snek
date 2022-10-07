cmake_minimum_required(VERSION 3.23)
project(Snek C)

set(CMAKE_C_STANDARD 99)

add_executable(Snek main.c console.c console.h)

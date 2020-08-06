cmake_minimum_required(VERSION 3.12)
project(CAESAR)

set(CMAKE_CXX_STANDARD 11)

add_executable(CAESAR file.c file.h caesar.c caesar.h main.c)
cmake_minimum_required(VERSION 3.15)
project(SpanningTree)

set(CMAKE_CXX_STANDARD 11)

add_executable(SpanningTree spanning_tree.c spanning_tree.h main.c test.c tree.c)
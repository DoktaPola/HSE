cmake_minimum_required(VERSION 3.12)
project(Card)

set(CMAKE_CXX_STANDARD 11)

add_executable(Card card.c card.h main.c pdf_des.cpp)
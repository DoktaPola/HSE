cmake_minimum_required(VERSION 3.15)
project(server_client)

set(CMAKE_CXX_STANDARD 11)

add_executable(server_client server.c client.c client.h server.h)

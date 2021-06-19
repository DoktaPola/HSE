cmake_minimum_required(VERSION 3.17)
project(bst)

set(CMAKE_CXX_STANDARD 17)
#set(SOURCES
#        include/task1.h
#        src/task1.cpp
#        )
#add_executable(${PROJECT_NAME} src/main1.cpp)
add_executable(bst include/task1.h src/main1.cpp src/task1.cpp)
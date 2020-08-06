cmake_minimum_required(VERSION 3.15)
project(CatalogTree)

set(CMAKE_CXX_STANDARD 11)

add_executable(CatalogTree main.c catalog_tree2.c catalog_tree.h test.c catalog_tree.c queue.c queue.h queue_2.c queue_2.h)
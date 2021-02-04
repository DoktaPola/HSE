cmake_minimum_required(VERSION 3.17)
project(Deanery)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR} PUBLIC external/bprinter/include)
add_library(bprinter STATIC
        external/bprinter/include/bprinter/table_printer.h
        external/bprinter/include/bprinter/impl/table_printer.tpp.h
        external/bprinter/src/table_printer.cpp
        )

add_executable(Deanery src/main.cpp src/Student.cpp include/Student.h src/Group.cpp include/Group.h src/Deanary.cpp include/Deanary.h src/Reader.cpp include/Reader.h src/Deanary.cpp include/Deanary.h)
target_link_libraries(Deanery bprinter)

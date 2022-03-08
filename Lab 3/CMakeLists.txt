cmake_minimum_required(VERSION 3.21)
project(Lab_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_3 main.cpp UI/io_operations/read_show.cpp UI/io_operations/read_show.h UI/menu/console.cpp UI/menu/console.h Service/problems/problems.cpp Service/problems/problems.h Service/tests/tests.cpp Service/tests/tests.h)

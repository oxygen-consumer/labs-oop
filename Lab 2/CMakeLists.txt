cmake_minimum_required(VERSION 3.21)
project(Lab_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_2 main.cpp UI/menu/console.cpp UI/menu/console.h UI/io_operations/read_show.cpp UI/io_operations/read_show.h Service/problems/problems.cpp Service/problems/problems.h Service/tests/tests.cpp Service/tests/tests.h)

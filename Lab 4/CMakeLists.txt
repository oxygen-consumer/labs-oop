cmake_minimum_required(VERSION 3.21)
project(Lab_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_4 main.cpp Domain/complex_num.cpp Domain/complex_num.h Tests/tests.cpp Tests/tests.h UI/console.cpp UI/console.h)

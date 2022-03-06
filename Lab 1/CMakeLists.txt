cmake_minimum_required(VERSION 3.21)
project(Lab_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Lab_1 main.cpp Problem/palindrom.cpp Problem/palindrom.h Tests/test_palindrom.cpp Tests/test_palindrom.h)
add_executable(Lab_1_single_file palindrom_single_file.cpp)
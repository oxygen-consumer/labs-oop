cmake_minimum_required(VERSION 3.21)
project(Lab_9)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_9 main.cpp Domain/Product.cpp Domain/Product.h Repository/Repo.cpp Repository/Repo.h Tests/Test.cpp Tests/Test.h)

cmake_minimum_required(VERSION 3.21)
project(Lab_7_live)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_7_live main.cpp Domain/vector.h Domain/transaction.cpp Domain/transaction.h Repository/repository.h Tests/tests.cpp Tests/tests.h)

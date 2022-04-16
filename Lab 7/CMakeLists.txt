cmake_minimum_required(VERSION 3.21)
project(Lab_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_7 main.cpp Domain/Entity/transaction.cpp Domain/Entity/transaction.h Domain/vector.h Repository/repository.h Tests/tests.h UI/menu.cpp UI/menu.h Service/transaction_service.cpp Service/transaction_service.h Domain/Entity/transaction_validator.cpp Domain/Entity/transaction_validator.h)

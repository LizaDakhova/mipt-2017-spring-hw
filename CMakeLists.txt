cmake_minimum_required(VERSION 3.6)
project(mipt-2017-spring-hw)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(lesson3
        src/cpp/lesson3/String.cpp
        src/cpp/lesson3/String.h)

add_executable(lesson3
        src/cpp/lesson4/main.cpp
        src/cpp/lesson4/Matrix.cpp
        src/cpp/lesson4/Matrix.h)

add_executable(lesson3
        src/cpp/lesson5/main.cpp
        src/cpp/lesson4/BigInt.cpp
        src/cpp/lesson4/BigInt.h)
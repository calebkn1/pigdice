cmake_minimum_required(VERSION 3.20)

project(PigDice)

set(CMAKE_CXX_STANDARD 20)

add_executable(PigDice
        PigDice.cpp
        die.cpp
        die.h
)
cmake_minimum_required(VERSION 3.20)

project(PigDice)

set(CMAKE_CXX_STANDARD 17)

add_executable(PigDice
        main.cpp
        PigDiceGame.cpp
        PigDiceGame.h
        Turn.cpp
        Turn.h
        Die.cpp
        Die.h
)
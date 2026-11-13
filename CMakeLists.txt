cmake_minimum_required(VERSION 3.20)

project(pigdice)

set(CMAKE_CXX_STANDARD 20)

add_executable(pigdice
        Main.cpp
        die.cpp
        die.h
        Turn.cpp
        Turn.h
        PigDiceGame.cpp
        PigDiceGame.h
        PigDiceGameV2.cpp
        PigDiceGameV2.h
        MultiPlayer.cpp
        MultiPlayer.h
)
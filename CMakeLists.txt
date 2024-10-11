cmake_minimum_required(VERSION 3.29)
project(hangman)

set(CMAKE_CXX_STANDARD 20)

add_executable(hangman src/main.cpp
        src/Game.cpp
        src/Game.h
)

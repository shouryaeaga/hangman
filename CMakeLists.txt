cmake_minimum_required(VERSION 3.29)
project(hangman)

set(CMAKE_CXX_STANDARD 20)

# When compiling for windows
#set(CMAKE_C_COMPILER "x86_64-w64-mingw32-gcc")
#set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-g++")
#set(CMAKE_SYSTEM_NAME Windows)
#set(CMAKE_SYSTEM_PROCESSOR x86_64)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/windows)

# When compiling for linux
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/linux)

add_executable(hangman src/main.cpp
        src/Game.cpp
        src/Game.h
)

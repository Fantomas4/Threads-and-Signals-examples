cmake_minimum_required(VERSION 3.10)
project(Threads-and-Signals-examples)

set(CMAKE_CXX_STANDARD 11)

add_executable(Threads-and-Signals-examples main.cpp ThreadClass.h ThreadClass.cpp ThreadClass2.cpp ThreadClass2.h)
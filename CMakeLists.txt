cmake_minimum_required(VERSION 3.23)
project(projekt)

set(CMAKE_CXX_STANDARD 23)

add_executable(projekt main.cpp Word.cpp Word.h WordSet.cpp WordSet.h)

cmake_minimum_required(VERSION 3.20)
project(esercitazione8)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(CMAKE_CXX_STANDARD 20)
add_executable(test_grafo main.cpp)
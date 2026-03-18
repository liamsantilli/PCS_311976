cmake_minimum_required(VERSION 3.20)
project(esercitazione1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

# programma esempio
add_executable(esempio_figura1 esempio_figura1.cpp)

# programma Esercizio 
add_executable(Esercizio_1 Esercizio_1.cpp)
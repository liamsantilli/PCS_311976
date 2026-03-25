cmake_minimum_required(VERSION 3.20)
project(Esercitazione2)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Compila il primo esercizio (Analisi Memoria)
add_executable(memoria esercizio_figura1.cpp)

# Compila il secondo esercizio (Media e Varianza)
add_executable(statistica Esercizio2.cpp)
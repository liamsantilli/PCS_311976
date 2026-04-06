cmake_minimum_required(VERSION 3.20)
project(esercitazione4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")


add_executable(misura_tempi misura_tempi.cpp timecounter.cpp)


enable_testing()
add_executable(esegui_test test_funzionali.cpp)
add_test(NAME test_ordinamento COMMAND esegui_test)
cmake_minimum_required(VERSION 3.20)
project(Dinos)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dinos main.cpp Dinosaurier.cpp Dinosaurier.h Herbivoren.cpp Herbivoren.h Karnivoren.cpp Karnivoren.h Utils.cpp Utils.h main.h)

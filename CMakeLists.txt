cmake_minimum_required(VERSION 3.15)
project(EVOLUTION__)

set(CMAKE_CXX_STANDARD 14)

add_executable(EVOLUTION__ main.cpp tests/test_EVOLUTION.cpp tests/test_EVOLUTION.h src/Animal.cpp src/Animal.h src/Herb.cpp src/Herb.h src/FitnessFunction.cpp src/FitnessFunction.h)
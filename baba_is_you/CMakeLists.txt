cmake_minimum_required(VERSION 3.5)

project(baba_is_you LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ask for all warnings and strict compliance with the standard
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")
add_executable(baba_is_you main.cpp direction.h direction.cpp position.h
    position.cpp MaterielType.cpp item.h item.cpp square.h square.cpp
    level.cpp level.h board.h
    )

install(TARGETS baba_is_you
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

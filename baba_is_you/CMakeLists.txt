cmake_minimum_required(VERSION 3.5)

project(baba_is_you LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ask for all warnings and strict compliance with the standard
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")
add_executable(baba_is_you direction.h direction.cpp position.h
    position.cpp item.h item.cpp square.h square.cpp
    level.cpp level.h board.cpp board.h
    status.cpp status.h
    type.cpp type.h
    text.h
    game.cpp game.h
    main-console.cpp
    view/view.h view/view.cpp
    controller/controller.h controller/controller.cpp
    )

install(TARGETS baba_is_you
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

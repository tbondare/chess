cmake_minimum_required(VERSION 3.10.2)
project(chess)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(unit_tests)
add_executable(chess
        main.cpp
        chessboard.cpp
        chessboard.hpp
        match.cpp
        match.hpp
        CommandInput.cpp
        CommandInput.hpp
        Chessman.cpp
        Chessman.hpp
        Structures.hpp
        unit_tests/test_knight.cpp Structures.cpp)
target_link_libraries (chess stdc++fs)
# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(TicTackToe Main.cpp BoardGame.cpp Console.cpp Game.cpp GameController.cpp GameUI.cpp TicTacToeGame.cpp UI.cpp BoardGame.h Console.h Game.h
        GameController.h GameUI.h TicTacToeGame.h UI.h)
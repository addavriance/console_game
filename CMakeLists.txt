cmake_minimum_required(VERSION 3.29)
project(console_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(console_game main.cpp
        engine.cpp
        engine.h
        player.cpp
        player.h
        tile.cpp
        tile.h
        location.cpp
        location.h
        item.cpp
        item.h
        mob.cpp
        mob.h
        utils.cpp
        utils.h)

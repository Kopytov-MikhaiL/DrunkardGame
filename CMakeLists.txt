cmake_minimum_required(VERSION 3.10)
project(DrunkardGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DrunkardGame
    main.cpp
    Card.cpp
    Deck.cpp
    Player.cpp
    Game.cpp
    Menu.cpp
)

set(CMAKE_CXX_STANDARD 17)

# Статическая линковка для MinGW
if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()

add_executable(MyApp main.cpp)

# Настройки для Release
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Release build - optimizing")
    add_compile_options(/O2)
endif()
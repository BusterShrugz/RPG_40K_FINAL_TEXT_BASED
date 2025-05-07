cmake_minimum_required(VERSION 3.30)
project(RPG_40K_FINAL_RE)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)
FetchContent_MakeAvailable(raylib)

add_executable(RPG_40K_FINAL_RE
    RPG_START_RE.cpp
    ChaosKnight_RE.cpp
    CharacterLog_RE.cpp
    OrkBoy_RE.cpp
    SpaceElf_RE.cpp
    SpaceMarine_RE.cpp
    SkillSet_RE.cpp
    Character_RE.cpp

    ChaosKnight_RE.h
    CharacterLog_RE.h
    OrkBoy_RE.h
    SpaceElf_RE.h
    SpaceMarine_RE.h
    SkillSet_RE.h
    Character_RE.h  
)

target_link_libraries(RPG_40K_FINAL_RE raylib)



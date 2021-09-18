cmake_minimum_required(VERSION 2.8...3.10)

project(ms)

set(SRC src/main.cpp
        src/personages/soldier_class.cpp
        src/personages/player_class.cpp
        src/personages/attack_behavior_interface.cpp
)

add_executable(${PROJECT_NAME} ${SRC})

include_directories(include)
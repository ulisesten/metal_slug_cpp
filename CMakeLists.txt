cmake_minimum_required(VERSION 2.8...3.10)

project(ms)

set(SRC src/main.cpp
        src/strategy/soldier_class.cpp
        src/strategy/player_class.cpp
        src/strategy/i_attack_behavior.cpp
        src/composite/game_element_set.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(${PROJECT_NAME} ${SRC})

include_directories(
        ${PROJECT_SOURCE_DIR}/src/strategy
        ${PROJECT_SOURCE_DIR}/src/composite
        ${PROJECT_SOURCE_DIR}/src/scenario
)

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)
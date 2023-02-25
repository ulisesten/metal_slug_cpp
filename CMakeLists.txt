cmake_minimum_required(VERSION 2.8...3.10)
project(ms)

execute_process(COMMAND  git submodule update --init --recursive
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

set(SRC src/main.cpp
        src/strategy/soldier_class.cpp
        src/strategy/player_class.cpp
        src/strategy/i_attack_behavior.cpp
        src/composite/game_element_set.cpp
        src/scenario/scenario.cpp
        src/scenario/scene_rects.cpp
        src/objects/base_object.cpp
        src/player_rects/clark_rects.cpp
        src/event_drivers/default_driver.cpp
)

set(CMAKE_BUILD_TYPE Debug)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(${PROJECT_NAME} ${SRC})

include_directories(
        ${PROJECT_SOURCE_DIR}/src/strategy
        ${PROJECT_SOURCE_DIR}/src/composite
        ${PROJECT_SOURCE_DIR}/src/scenario
        ${PROJECT_SOURCE_DIR}/src/objects
        ${PROJECT_SOURCE_DIR}/src/player_rects
        ${PROJECT_SOURCE_DIR}/src/event_drivers
)

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)
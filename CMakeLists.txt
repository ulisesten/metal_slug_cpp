cmake_minimum_required(VERSION 2.8...3.10)

project(ms)

set(SRC src/main.cpp
        src/strategy/soldier_class.cpp
        src/strategy/player_class.cpp
        src/strategy/attack_behavior_interface.cpp

        src/sdl/graphics.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(${PROJECT_NAME} ${SRC})

include_directories(${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)
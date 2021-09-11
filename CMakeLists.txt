cmake_minimum_required(VERSION 2.8...3.10)

project(template)

set(SRC src/main.cpp
        src/my_class.cpp
)

add_executable(${PROJECT_NAME} ${SRC})

include_directories(include)
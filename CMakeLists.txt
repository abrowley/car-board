cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)
set(project_name car_board)
project(${project_name} C CXX ASM)

execute_process(COMMAND git describe --tags --always OUTPUT_STRIP_TRAILING_WHITESPACE
        OUTPUT_VARIABLE GIT_REPO_VERSION)
configure_file("src/car-board-version.h.in" "piciot-version.h")

add_executable(
        ${project_name}
        src/main.cpp
)

cmake_minimum_required(VERSION 3.16)

project(AA-Matrix DESCRIPTION "COMS4032A AA Assignment 3: Disjoint Sets" LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED On)
set(CMAKE_C_EXTENSIONS Off)

add_executable(linked-experiment
    src/linked-experiment.c src/linked-disjoint-set.c
)
target_link_libraries(linked-experiment m)
target_include_directories(linked-experiment PUBLIC include)
target_link_directories(linked-experiment PRIVATE src)

add_executable(forest-experiment
    src/forest-experiment.c src/forest-disjoint-set.c
)
target_link_libraries(forest-experiment m)
target_include_directories(forest-experiment PUBLIC include)
target_link_directories(forest-experiment PRIVATE src)
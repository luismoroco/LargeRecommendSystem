cmake_minimum_required(VERSION 3.22.1)
project(LargeRecommendSys C)

set(CMAKE_C_STANDARD 17)

file(GLOB SOURCES "src/*.c")

add_executable(LargeRecommendSys main.c ${SOURCES})
target_include_directories(LargeRecommendSys PRIVATE include)
target_link_libraries(LargeRecommendSys m)

cmake_minimum_required(VERSION 3.22.1)
project(LargeRecommendSys C)

set(CMAKE_C_STANDARD 17)

add_executable(LargeRecommendSys main.c src/Node.c src/LinkedList.c src/MatrixSparse.c lib/binarySearch.c)
target_include_directories(LargeRecommendSys PRIVATE include)
target_link_libraries(LargeRecommendSys m)

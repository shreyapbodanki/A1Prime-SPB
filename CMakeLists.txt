cmake_minimum_required(VERSION 3.12)
project(A1Prime LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(prime STATIC prime.cpp)
target_include_directories(prime PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main_exec main.cpp)
target_link_libraries(main_exec PRIVATE prime)

add_executable(test.out test.cpp)
target_link_libraries(test.out PRIVATE prime)

enable_testing()
add_test(NAME a1prime_tests COMMAND test.out)

cmake_minimum_required(VERSION 3.28)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

add_executable(leetcode main.cpp)

target_compile_options(leetcode PRIVATE
    -Wall
    -Wextra
    -fsanitize=address,undefined
)

target_link_options(leetcode PRIVATE
    -fsanitize=address,undefined
)
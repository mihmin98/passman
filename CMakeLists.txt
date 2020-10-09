cmake_minimum_required(VERSION 3.13)
project(passman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

# Create main library
add_library(main_lib "")
add_subdirectory(src)

# Create executable
add_executable(passman
    src/main.cpp
)

target_link_libraries(passman
    PRIVATE
        main_lib
)

target_compile_options(passman
    PRIVATE
        -Wall -Wextra
)

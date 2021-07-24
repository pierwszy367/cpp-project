cmake_minimum_required(VERSION 3.9)

project(cpp_project)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(cpp_project main.cpp)
target_compile_features(cpp_project PRIVATE cxx_lambda_init_captures)

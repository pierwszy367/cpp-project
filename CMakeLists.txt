cmake_minimum_required(VERSION 3.9)

project(cpp_project)

if (CMAKE_COMPILER_IS_GNUCC)
    option(ENABLE_COVERAGE "Enable coverage reporting for gcc" FALSE)
    
    if (ENABLE_COVERAGE)
        add_compile_options(--coverage -O0)
    endif()
endif()


if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(cpp_project main.cpp)
target_compile_features(cpp_project PRIVATE cxx_lambda_init_captures)
target_link_libraries(cpp_project --coverage)

enable_testing()
add_executable(tester tester.cpp)
target_link_libraries(tester --coverage)
add_test(Tester tester)


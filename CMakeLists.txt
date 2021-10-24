cmake_minimum_required(VERSION 3.13)

project(cpp_project)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable Test Builds" ON)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)
include(cmake/Coverage.cmake)
enable_coverage(project_options)

add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

add_subdirectory(src)

if(ENABLE_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()

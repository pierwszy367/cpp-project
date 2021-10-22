add_executable(tester tester.cpp)
target_link_libraries(tester PRIVATE project_options project_warnings)
add_test(Tester tester)
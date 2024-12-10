# Unit Test Example
add_executable(example_tests tests.cpp)
target_link_libraries(example_tests PRIVATE doctest::doctest)
add_test(NAME examples_tests COMMAND example_tests)

add_library(execution execution_manager.cpp)
target_include_directories(execution PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(execution_tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cpp)
target_link_libraries(execution_tests PRIVATE doctest::doctest execution)
add_test(NAME execution_tests COMMAND execution_tests)

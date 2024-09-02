cmake_minimum_required(VERSION 3.5.0)

project(polish_notation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

include(CTest)
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)

cmake_minimum_required(VERSION 3.20)
project(linkedhashset)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(linkedhashset main.cpp student.cpp student.h hashtree.cpp hashtree.h linkedhs.cpp linkedhs.h linkedhashset_test/linkedhashset_test.cpp)

SET(WARN_FLAGS "-Wall -Wpedantic -Wextra")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARN_FLAGS} ${ASAN_OPTIONS}")

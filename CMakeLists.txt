cmake_minimum_required(VERSION 3.20)
project(linkedhashset VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_executable(relinkedhashset main.cpp student.cpp linkedhashset.cpp linkedhashset_test.cpp)

add_executable(linkedhashset_test linkedhashset.cpp student.cpp linkedhashset_test.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

SET(WARN_FLAGS "-Wall -Wpedantic -Wextra")
# CR: https://github.com/google/sanitizers/wiki/AddressSanitizer
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARN_FLAGS} ${ASAN_OPTIONS}")

enable_testing()

target_link_libraries(
        linkedhashset_test
        GTest::gtest_main
)

include(GoogleTest)
#gtest_discover_tests(linkedhashset_test)
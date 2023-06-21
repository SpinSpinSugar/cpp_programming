cmake_minimum_required(VERSION 3.14)


set(CPP_COMPILER "clang++-15")
set(C_COMPILER "clang-15")

set(CMAKE_CXX_COMPILER ${CPP_COMPILER})
set(CMAKE_C_COMPILER ${C_COMPILER})

project(my_project)

include_directories(${CMAKE_SOURCE_DIR}/inc)
link_directories(${CMAKE_SOURCE_DIR}/lib)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)

FetchContent_MakeAvailable(googletest)


# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-${CMAKE_CXX_FLAGS} -fsanitize=thread -std=libc++ -O0 -g -Wshadow -Wpedantic -Wconversion -Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-${CMAKE_CXX_FLAGS} -O3 -DNDEBUG -Wshadow -Wpedantic -Wconversion -Wall")

add_executable(Tests packaged_task.cpp)

target_link_libraries(
    Tests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Tests)


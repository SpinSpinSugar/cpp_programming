cmake_minimum_required(VERSION 3.10)
project(WC3_Classes)

set(CMAKE_DEBUG_POSTFIX d)
add_library(tutorial_compiler_flags INTERFACE)

# add the executable
add_executable(
    ${PROJECT_NAME}
    ${PROJECT_NAME}.cpp
    Heroes.cpp
    MainClasses.cpp
    Objects.cpp
)
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_BINARY_DIR}")
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}")
cmake_minimum_required(VERSION 3.10)
project(optimath)

# Add Catch2 subdirectory to the project
add_subdirectory(Catch2)

# Define sources to be compiled
file(GLOB OPTIMATH_SOURCES "optimath/*.cpp")

# Create static library
add_library(optimath_static STATIC ${OPTIMATH_SOURCES})

# Create shared library
add_library(optimath_shared SHARED ${OPTIMATH_SOURCES})

# Define the test executable
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(optimath_tests ${TEST_SOURCES})

# Link the test executable against the static library and Catch2
target_link_libraries(optimath_tests PRIVATE optimath_static Catch2::Catch2WithMain)

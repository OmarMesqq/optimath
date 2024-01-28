cmake_minimum_required(VERSION 3.10)
project(optimath)

# Add Catch2 subdirectory to the project
add_subdirectory(Catch2)

# Define sources to be compiled
file(GLOB SOURCES "optimath/*.cpp")

# Define the test executable
add_executable(optimath ${SOURCES})

# Link against Catch2
target_link_libraries(optimath PRIVATE Catch2::Catch2WithMain)

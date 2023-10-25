cmake_minimum_required(VERSION 3.10)
project(optimath)

# Add Catch2 subdirectory
add_subdirectory(Catch2)

file(GLOB SOURCES "cpp/*.cpp")

# Define your executable
add_executable(optimath ${SOURCES})

# Link against Catch2
target_link_libraries(optimath PRIVATE Catch2::Catch2WithMain)


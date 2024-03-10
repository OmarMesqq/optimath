cmake_minimum_required(VERSION 3.10)
project(optimath)

include(FetchContent)

FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.2
)

FetchContent_MakeAvailable(catch2)

# Create the examples executable
file(GLOB EXAMPLE_SOURCES "examples/*.cpp")
add_executable(examples ${EXAMPLE_SOURCES})

# Create the test executable
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(optimath_tests ${TEST_SOURCES})
target_link_libraries(optimath_tests PRIVATE Catch2::Catch2WithMain) # Link it against Catch2


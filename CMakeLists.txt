cmake_minimum_required(VERSION 3.10.0)
project(interview VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB LIB_SOURCES "src/*.cpp")
add_library(SolutionLib ${LIB_SOURCES})

include_directories(include)

add_executable(main src/main.cpp)
target_link_libraries(main SolutionLib)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests SolutionLib ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

# add_test(NAME EanValidationTests COMMAND tests)
add_test(NAME SolutionTests COMMAND tests)

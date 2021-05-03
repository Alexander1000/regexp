cmake_minimum_required(VERSION 3.7)

# compiler options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

project(regexp-tests)

set(REGEXP_SOURCES
    ../src/regexp.cpp
)

# find_library(IO_BUFFER libio-buffer.a)
# message(STATUS "Found io-buffer library: ${IO_BUFFER}")

find_library(CPP_UNIT_TEST libcpp-unit-test.a)
message(STATUS "Found cpp-unit-test: ${CPP_UNIT_TEST}")

include_directories(/usr/local/include)

add_executable(
    ${PROJECT_NAME} main.cpp
    ${REGEXP_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
    ${CPP_UNIT_TEST}
)

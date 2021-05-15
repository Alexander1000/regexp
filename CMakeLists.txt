cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

set(REGEXP_SOURCES
    src/regexp.cpp
    src/lexer.cpp
    src/token/token.cpp
    src/token/token_map.cpp
    src/syntax/tree.cpp
    src/predicate/predicate.cpp
    src/predicate/alphabet.cpp
    src/predicate/negative.cpp
    src/predicate/oneof.cpp
)

if(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)
    set(CMAKE_INSTALL_INCLUDEDIR include)
endif(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)

# installation of regexp CXX library headers
install(DIRECTORY include/regexp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

find_library(IO_BUFFER libio-buffer.a)
message(STATUS "Found io-buffer library: ${IO_BUFFER}")

find_library(SYNTAX_TREE_LIB libsyntax-tree-lib.a)
message(STATUS "Found syntax-tree library: ${SYNTAX_TREE_LIB}")

#-------#
# TESTS #
#-------#

project(regexp-tests)

find_library(CPP_UNIT_TEST libcpp-unit-test.a)
message(STATUS "Found cpp-unit-test: ${CPP_UNIT_TEST}")

include_directories(
    include
    tests/include
    /usr/local/include
)

set(REGEXP_SOURCES_TEST
    tests/src/main.cpp
    ${REGEXP_SOURCES}
    tests/src/asserts.cpp
    tests/src/test-cases/lexer_tests.cpp
    tests/src/test-cases/lexer_capture_tests.cpp
    tests/src/test-cases/syntax_tests.cpp
    tests/src/test-cases/predicate_tests.cpp
    tests/src/test-cases/expression_tests.cpp
)

add_executable(
    ${PROJECT_NAME} tests/src/main.cpp
    ${REGEXP_SOURCES_TEST}
)

target_link_libraries(${PROJECT_NAME}
    ${CPP_UNIT_TEST}
    ${IO_BUFFER}
    ${SYNTAX_TREE_LIB}
)

#----------------#
# Static library #
#----------------#

project(regexp VERSION 0.0.1 DESCRIPTION "regexp")

add_library(${PROJECT_NAME} STATIC ${REGEXP_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION 1)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/regexp.h)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "regexp")
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS -fPIC)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

include_directories(/usr/local/include)

target_link_libraries(${PROJECT_NAME}
    ${IO_BUFFER}
    ${SYNTAX_TREE_LIB}
)

install (TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
    COMPONENT library
)

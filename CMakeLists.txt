cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

set(REGEXP_SOURCES
    src/regexp.cpp
    src/lexer.cpp
    src/token.cpp
)

if(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)
    set(CMAKE_INSTALL_INCLUDEDIR include)
endif(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)

# installation of regexp CXX library headers
install(DIRECTORY include/regexp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

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

install (TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
    COMPONENT library
)

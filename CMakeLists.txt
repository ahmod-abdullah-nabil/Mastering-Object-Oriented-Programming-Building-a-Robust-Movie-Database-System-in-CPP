cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MovieDatabaseSystem VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Source files
set(SOURCES
    main.cpp
    Movie.cpp
    MovieDatabase.cpp
)

# Header files
set(HEADERS
    Movie.h
    MovieDatabase.h
)

# Create executable
add_executable(MovieDatabase ${SOURCES} ${HEADERS})

# Installation rules
install(TARGETS MovieDatabase DESTINATION bin)

# Print build information
message(STATUS "===========================================")
message(STATUS "Movie Database System - CMake Configuration")
message(STATUS "===========================================")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "===========================================")

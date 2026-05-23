cmake_minimum_required(VERSION 3.10)

# Project name
project(NEURAL-NET)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    main.cpp
    neural_networking.cpp
    neuron.cpp
)

# Header files
set(HEADERS
    neural_networking.h
    neuron.h
)

# Create executable
add_executable(neural_net
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(neural_net PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
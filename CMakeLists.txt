cmake_minimum_required(VERSION 3.10)
project(KTrussExperiment)

# Use C++17
set(CMAKE_CXX_STANDARD 17)

# Include headers
include_directories(include)

# Add all source files in src/
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(ktruss ${SOURCES})

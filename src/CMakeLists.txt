# src/CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(multiscale_engine LANGUAGES CXX)

# Collect all .cpp sources under src/
file(GLOB_RECURSE ENGINE_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# Create the static library from those sources
add_library(multiscale_engine STATIC ${ENGINE_SOURCES})

# Expose the include directory for client code (so they can #include <core/sim_object.hpp>)
target_include_directories(multiscale_engine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link SFML (engine code needs to draw/render)
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
target_link_libraries(multiscale_engine
        PUBLIC
        sfml-graphics
        sfml-window
        sfml-system
)
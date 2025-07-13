# src/CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(multiscale_engine LANGUAGES CXX)

#gets all headers and sources in src/
file(GLOB_RECURSE ENGINE_HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h++
)

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

#creates a static library target
add_library(multiscale_engine STATIC
    ${ENGINE_SOURCES}
    ${ENGINE_HEADERS}
        config/math_constants.hpp
        config/physics_constants.hpp
        config/sim_constants.hpp
        config/render_constants.hpp
)

#exposes the include directory so that files can #include <core/sim_object.hpp>, etc.
target_include_directories(multiscale_engine
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

#links SFML for the engine code to use
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
target_link_libraries(multiscale_engine
    PUBLIC
    sfml-graphics
    sfml-window
    sfml-system
)

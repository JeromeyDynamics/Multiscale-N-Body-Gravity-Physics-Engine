cmake_minimum_required(VERSION 3.15)
project(multiscale_engine LANGUAGES CXX)

#gets all .cpp files under src/
file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(multiscale_engine STATIC ${ENGINE_SOURCES})

target_include_directories(multiscale_engine
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
target_link_libraries(multiscale_engine
        PUBLIC sfml-graphics sfml-window sfml-system
)
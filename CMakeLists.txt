cmake_minimum_required(VERSION 3.15)
project(Multiscale_NBody_Gravity LANGUAGES CXX)

cmake_policy(SET CMP0074 NEW)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#this keeps the set up for vcpkg even though it's not used for SFML
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

#adds SFML to the project
set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML-2.6.2/lib/cmake/SFML" CACHE PATH "")
find_package(SFML 2.6 COMPONENTS graphics window system
        PATHS "${SFML_DIR}"
        NO_DEFAULT_PATH
        REQUIRED)

add_executable(${PROJECT_NAME} main.cpp
        examples/simple/ball_collision.cpp
        src/core/simulation.cpp
        src/core/simulation.h++
        src/core/sim_object.h++
        src/core/object_manager.cpp
        src/core/object_manager.h++
        src/core/integrator.cpp
        src/core/integrator.h++
        src/entities/orbit_object.cpp
        src/entities/orbit_object.h++
        src/entities/central_mass.cpp
        src/entities/central_mass.h++
        src/physics/gravity.cpp
        src/physics/gravity.h++
        src/physics/vector_math.cpp
        src/physics/vector_math.h++
        src/physics/constants.h++
        src/render/renderer.cpp
        src/render/renderer.h++
        src/render/color_palette.h++
)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/external/SFML-2.6.2/bin"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(tests)
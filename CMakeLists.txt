cmake_minimum_required(VERSION 3.15)
project(Multiscale_NBody_Gravity LANGUAGES CXX)

cmake_policy(SET CMP0074 NEW)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#adds the Vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

#finds SFML for the main file
set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML-2.6.2/lib/cmake/SFML" CACHE PATH "")
find_package(SFML 2.6 COMPONENTS graphics window system
    PATHS "${SFML_DIR}"
    NO_DEFAULT_PATH
    REQUIRED
)

#builds the engine library from src/
add_subdirectory(src)

#builds the main executable
add_executable(${PROJECT_NAME}
    main.cpp
)

#links the engine library and SFML
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    multiscale_engine
    sfml-graphics
    sfml-window
    sfml-system
)

#copies SFML DLLs after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/external/SFML-2.6.2/bin"
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

#adds build examples and tests in their own targets
add_subdirectory(examples)
add_subdirectory(tests)
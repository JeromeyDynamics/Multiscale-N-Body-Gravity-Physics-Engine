set(EXAMPLES
        ball_collision
        attraction_between_objects
)

foreach(EXE IN LISTS EXAMPLES)
    # 1)create the executable
    add_executable(${EXE} ${EXE}.cpp)

    # 2)link SFML
    target_link_libraries(${EXE}
            PRIVATE
            sfml-graphics
            sfml-window
            sfml-system
    )

    # 3)copy SFML DLLs after build
    add_custom_command(TARGET ${EXE} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/external/SFML-2.6.2/bin"
            $<TARGET_FILE_DIR:${EXE}>
    )
endforeach()
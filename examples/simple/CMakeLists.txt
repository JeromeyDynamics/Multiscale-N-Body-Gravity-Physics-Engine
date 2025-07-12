add_executable(ball_collision ball_collision.cpp)

target_link_libraries(ball_collision
    PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)

add_custom_command(TARGET ball_collision POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/external/SFML-2.6.2/bin"
    $<TARGET_FILE_DIR:ball_collision>
)

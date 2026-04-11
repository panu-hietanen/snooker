cmake_minimum_required(VERSION 3.20)
project(snooker C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.5
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(raylib)

add_executable(snooker 
    src/main.c
    src/vec2.c
    src/ball.c
    src/utils.c
)

target_include_directories(snooker PRIVATE src)

target_link_libraries(snooker PRIVATE raylib)

target_compile_options(snooker PRIVATE
    $<$<C_COMPILER_ID:MSVC>:/W4 /WX>
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(snooker PRIVATE
        $<$<C_COMPILER_ID:MSVC>:/fsanitize=address>
    )
    target_link_options(snooker PRIVATE
        $<$<C_COMPILER_ID:MSVC>:/INCREMENTAL:NO>
    )
endif()

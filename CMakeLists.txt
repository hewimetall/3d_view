cmake_minimum_required(VERSION 3.16)
project(s21_view3d LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_APP "Build the graphical 3D viewer application" ON)
option(ENABLE_COVERAGE "Build test target with gcov coverage flags" OFF)

include(FetchContent)
include(CTest)

set(PROJECT_SOURCES
    3dmath.c
    input.c
    parser.c
    utils.c
)

if(BUILD_APP)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG dbc56a87da87d973a9c5baa4e7438a9d20121d28 # 6.0
    )
    FetchContent_MakeAvailable(raylib)

    FetchContent_Declare(
        raygui
        GIT_REPOSITORY https://github.com/raysan5/raygui.git
        GIT_TAG 25c8c65a6e5f0f4d4b564a0343861898c6f2778b # 4.0
    )
    FetchContent_MakeAvailable(raygui)

    add_library(raygui INTERFACE)
    target_include_directories(raygui INTERFACE ${raygui_SOURCE_DIR}/src)

    add_executable(${PROJECT_NAME}
        main.c
        ui.c
        project.h
        terminal.h
        ${PROJECT_SOURCES}
    )
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib raygui m)

    if(APPLE)
        target_link_libraries(${PROJECT_NAME} PRIVATE
            "-framework IOKit"
            "-framework Cocoa"
            "-framework OpenGL"
        )
    endif()

    if(DEFINED PLATFORM AND PLATFORM STREQUAL "Web")
        set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
    endif()
endif()

if(BUILD_TESTING)
    add_executable(unit_tests
        tests/test.c
        tests/test.h
        project.h
        ${PROJECT_SOURCES}
    )
    target_compile_definitions(unit_tests PRIVATE UNIT_TEST)
    target_link_libraries(unit_tests PRIVATE m)
    add_test(NAME unit_tests COMMAND unit_tests)

    if(ENABLE_COVERAGE)
        if(NOT CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
            message(FATAL_ERROR "Coverage requires GCC or Clang")
        endif()

        target_compile_options(unit_tests PRIVATE --coverage -O0 -g)
        target_link_options(unit_tests PRIVATE --coverage)

        find_package(Python3 REQUIRED COMPONENTS Interpreter)
        add_custom_target(coverage
            COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
            COMMAND ${Python3_EXECUTABLE}
                ${CMAKE_CURRENT_SOURCE_DIR}/tests/coverage.py
                --build-dir ${CMAKE_CURRENT_BINARY_DIR}
                --threshold 93
                --sources ${PROJECT_SOURCES}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            DEPENDS unit_tests
            VERBATIM
        )
    endif()
endif()
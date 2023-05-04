cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(s21_view3d)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 4.2.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED

if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

set(RAYGUI_VERSION 3.2)
find_package(raygui ${RAYGUI_VERSION} QUIET) # QUIET or REQUIRED

include(ExternalProject)
FetchContent_Declare(
                raygui
                URL https://github.com/raysan5/raygui/archive/refs/tags/${RAYGUI_VERSION}.tar.gz
    )
FetchContent_MakeAvailable(raygui)
include_directories(${raygui_SOURCE_DIR}/src)
# Directory Variables
set(RAYGUI_ROOT ${raygui_SOURCE_DIR})
set(RAYGUI_SRC ${raygui_SOURCE_DIR}/src)
set(RAYGUI_EXAMPLES ${raygui_SOURCE_DIR}/examples)
add_library(raygui INTERFACE)
file(GLOB raygui_sources ${RAYGUI_SRC}/*.h)
set(RAYGUI_HEADERS ${raygui_sources})
# OpenGL
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

# Our Project
add_executable(${PROJECT_NAME}  main.c parser.c project.h utils.c ui.c 3dmath.c)
add_executable(test tests/test.c tests/main.c tests/test.h  parser.c project.h utils.c ui.c 3dmath.c)

SET(CMAKE_C_FLAGS "-fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")

target_link_libraries(${PROJECT_NAME} raylib raygui)
target_link_libraries(test raylib raygui check subunit gcov)
#SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
    target_link_libraries(test "-framework IOKit")
    target_link_libraries(test "-framework Cocoa")
    target_link_libraries(test "-framework OpenGL")

endif()
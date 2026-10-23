project(Flint)


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/glfw)


file(GLOB_RECURSE FLINT_SOURCES
    "src/*.h"
    "src/*.cpp"
)

add_library(Flint SHARED ${FLINT_SOURCES}
        src/Flint/events/event.h
        src/Flint/events/key_event.h
        src/Flint/events/application_event.h
        src/Flint/events/mouse_event.h
        src/Flint/flint_pch.h
        src/Flint/flint_pch.cpp
        src/Flint/window.h
        src/Platform/Linux/LinuxWindow.cpp
        src/Platform/Linux/LinuxWindow.h
        src/Flint/layer.cpp
        src/Flint/layer.h
        src/Flint/layer_stack.cpp
        src/Flint/layer_stack.h)

target_include_directories(Flint PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include
)

target_precompile_headers(Flint PRIVATE
    src/Flint/flint_pch.h
)

find_package(OpenGL REQUIRED)

target_link_libraries(Flint PRIVATE
    glfw
    OpenGL::GL
)

target_compile_definitions(Flint PRIVATE
        FLINT_BUILD_DLL
        FMT_HEADER_ONLY
)

set_target_properties(Flint PROPERTIES CXX_VISIBILITY_PRESET hidden)
set_target_properties(Flint PROPERTIES VISIBILITY_INLINES_HIDDEN ON)
set_target_properties(Flint PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_compile_options(Flint PRIVATE -Wno-attributes)

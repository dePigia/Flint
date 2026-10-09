project(Flint)


file(GLOB_RECURSE FLINT_SOURCES
    "src/*.h"
    "src/*.cpp"
)

add_library(Flint SHARED ${FLINT_SOURCES}
        src/Flint/events/event.h
        src/Flint/events/key_event.h
        src/Flint/events/application_event.h
        src/Flint/events/mouse_event.h)

target_include_directories(Flint PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
)

target_compile_definitions(Flint PRIVATE FLINT_BUILD_DLL)

set_target_properties(Flint PROPERTIES CXX_VISIBILITY_PRESET hidden)
set_target_properties(Flint PROPERTIES VISIBILITY_INLINES_HIDDEN ON)
set_target_properties(Flint PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_compile_options(Flint PRIVATE -Wno-attributes)

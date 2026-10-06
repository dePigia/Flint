project(Flint)


add_library(Flint SHARED
        src/Flint/core.h
        src/Flint/application.cpp
        src/Flint/application.h
        src/flint.h
        src/Flint/entry-point.h
        src/Flint/log.cpp
        src/Flint/log.h
)

target_include_directories(Flint PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
)

target_compile_definitions(Flint PRIVATE FLINT_BUILD_DLL)

set_target_properties(Flint PROPERTIES CXX_VISIBILITY_PRESET hidden)
set_target_properties(Flint PROPERTIES VISIBILITY_INLINES_HIDDEN ON)
set_target_properties(Flint PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_compile_options(Flint PRIVATE -Wno-attributes)

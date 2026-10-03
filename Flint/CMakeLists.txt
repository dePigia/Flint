project(Flint)


add_library(Flint SHARED
    src/Test.cpp
    src/Test.h
)

target_include_directories(Flint PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_compile_definitions(Flint PRIVATE FLINT_BUILD_DLL)

set_target_properties(Flint PROPERTIES CXX_VISIBILITY_PRESET hidden)
set_target_properties(Flint PROPERTIES POSITION_INDEPENDENT_CODE ON)

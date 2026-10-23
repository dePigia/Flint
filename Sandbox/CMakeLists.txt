project(Sandbox)


file(GLOB_RECURSE SANDBOX_SOURCES
        "src/*.h"
        "src/*.cpp"
)

add_executable(Sandbox ${SANDBOX_SOURCES})

target_include_directories(Sandbox PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../Flint/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../Flint/vendor/spdlog/include
)

target_link_libraries(Sandbox PRIVATE Flint)

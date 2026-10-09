project(Sandbox)


file(GLOB_RECURSE SANDBOX_SOURCES
        "src/*.h"
        "src/*.cpp"
)

add_executable(Sandbox ${SANDBOX_SOURCES})

target_link_libraries(Sandbox PRIVATE Flint)

project(Sandbox)

add_executable(Sandbox
        src/sandbox-app.cpp
)

target_link_libraries(Sandbox PRIVATE Flint)

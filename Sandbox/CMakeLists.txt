project(Sandbox)

add_executable(Sandbox
    src/Application.cpp
)

target_link_libraries(Sandbox PRIVATE Flint)

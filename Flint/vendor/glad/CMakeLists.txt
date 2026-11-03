cmake_minimum_required(VERSION 3.20)
project(glad)

add_library(glad STATIC
    src/glad.c
)

target_include_directories(glad PUBLIC
    include
)

#set_target_properties(glad PROPERTIES POSITION_INDIPENDENT_CODE ON)
target_compile_options(glad PRIVATE -fPIC)
# CMake minimum required version
cmake_minimum_required(VERSION 3.10)

# Project name
project(glad)



# Specify the include directory
include_directories(include)
include_directories(include)

# Add the source files
set(GLAD_SOURCES
    src/glad.c
)

# Create a static library
add_library(glad STATIC ${GLAD_SOURCES})

# Ensure the glad.c file is compiled with -fPIC
set_target_properties(glad PROPERTIES POSITION_INDEPENDENT_CODE ON)


# If you prefer a shared library, use:
# add_library(glad SHARED ${GLAD_SOURCES})

# Specify the include directories for the glad target
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# If you want to add GLAD to your main project, use:
# target_link_libr

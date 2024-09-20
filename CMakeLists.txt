cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Duke)

# Enable C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE DUKE_SOURCE CONFIGURE_DEPENDS 
        "${CMAKE_CURRENT_SOURCE_DIR}/Duke/src/Duke/**.cpp" 
        "${CMAKE_CURRENT_SOURCE_DIR}/Duke/src/Duke/**.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Duke/src/**.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Duke/src/**.cpp"
        )
        # "${CMAKE_CURRENT_SOURCE_DIR}/Duke/src/vendor/glm/glm**.h"

        
# Add the static library
add_library(Duke SHARED ${DUKE_SOURCE})

target_compile_definitions(Duke
    PUBLIC DK_BUILD_DLL  _WIN32
)

# Add the precompiled header
target_precompile_headers(Duke PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Duke/src/dkpch.h)

# Specify include directories for the library (if needed)
target_include_directories(Duke PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Duke)






project(Sandbox)
# Add the sandbox executable
add_executable(Sandbox
    Sandbox/src/sandbox.cpp
)

target_include_directories(Duke PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Duke/src)


# Link the static library to the sandbox executable
target_link_libraries(Sandbox PRIVATE Duke)


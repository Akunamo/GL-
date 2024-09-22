# ImGui CMakeLists.txt

# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Set project name
project(ImGui VERSION 1.0 LANGUAGES CXX)

# Set ImGui source files
set(IMGUI_SOURCES
    "imgui.cpp"
    "imgui_draw.cpp"
    "imgui_tables.cpp"
    "imgui_widgets.cpp"
    "imgui_demo.cpp"
)

file(GLOB_RECURSE CPP_SOURCE backends/**cpp)

# Set ImGui header files
set(IMGUI_HEADERS
    "imconfig.h"
    "imgui.h"
    "imgui_internal.h"
    "imstb_rectpack.h"
    "imstb_textedit.h"
    "imstb_truetype.h"
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/backends)

# Add ImGui library target
add_library(${PROJECT_NAME} STATIC ${IMGUI_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set C++ standard
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    POSITION_INDEPENDENT_CODE ON
)


cmake_minimum_required(VERSION 3.10)
project(GameEngine VERSION 1.0 LANGUAGES CXX)

# Set cpp standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# enable compile_commands.json for LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default to a reasonable build type if not set
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING
    "Choose the type of build (Debug, Release, RelWithDebInfo, MinSizeRel)" FORCE)
endif()

# Enable warnings (you can tweak per-compiler later)
if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Optional toggles
option(BUILD_SANBOX "Build the Sandbox test application" ON)
option(BUILD_EDITOR "Build the Editor application" OFF)

# -----------------------------
# Subdirectories
# -----------------------------
add_subdirectory(Engine)

if(BUILD_SANBOX)
  add_subdirectory(Sandbox)
endif()

if(BUILD_EDITOR)
  add_subdirectory(Editor)
endif()

# Engine/CMakeLists.txt

add_library(MyEngine STATIC)

target_sources(MyEngine
    PRIVATE
        Core/Math.cpp
        Platform/Window.cpp
        Render/Texture2D.cpp
        Audio/AudioEngine.cpp
        External/imgui/imgui.cpp
        External/imgui/imgui_draw.cpp
        External/imgui/imgui_tables.cpp
        External/imgui/imgui_widgets.cpp
        External/imgui/backends/imgui_impl_glfw.cpp
        External/imgui/backends/imgui_impl_opengl3.cpp
)

# Our own headers live under Engine/
target_include_directories(MyEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# ---- Eigen integration ----
find_package(Eigen3 REQUIRED NO_MODULE)

# Get Eigen's include directory from the imported target
get_target_property(EIGEN3_INCLUDE_DIR Eigen3::Eigen INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "Eigen include dir: ${EIGEN3_INCLUDE_DIR}")

# Explicitly add Eigen's include dir to MyEngine
target_include_directories(MyEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${EIGEN3_INCLUDE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/External
        ${CMAKE_CURRENT_SOURCE_DIR}/External/imgui
        ${CMAKE_CURRENT_SOURCE_DIR}/External/imgui/backends
)

# ---- GLFW integration ----
find_package(glfw3 REQUIRED)
# target_link_libraries(MyEngine PUBLIC glfw)

# ---- OpenGL integration ----
find_package(OpenGL REQUIRED)

target_compile_definitions(MyEngine PUBLIC GL_SILENCE_DEPRECATION)

target_link_libraries(MyEngine
    PUBLIC
        Eigen3::Eigen
        glfw
        OpenGL::GL
)

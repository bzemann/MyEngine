# Editor/CMakeLists.txt
add_executable(Editor
    main_editor.cpp
    EditorApp.cpp
)

target_link_libraries(Editor
    PRIVATE
        MyEngine
)

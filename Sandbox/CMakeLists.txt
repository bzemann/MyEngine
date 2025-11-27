# Sandbox/CMakeLists.txt
add_executable(Sandbox
    main_sandbox.cpp
)

target_link_libraries(Sandbox
    PRIVATE
        MyEngine
)

#include <iostream>
#include <GLFW/glfw3.h>

#include "Platform/Window.hpp"
#include "Audio/AudioEngine.hpp"

// ImGui
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

int main() {
    using namespace Myeng;

    try {
        WindowDesc desc;
        desc.title  = "MyEngine Sandbox (ImGui)";
        desc.width  = 1280;
        desc.height = 720;
        desc.vsync  = true;

        Window window(desc);
        Myeng::AudioEngine::init();

        Myeng::AudioEngine::playSound("Sandbox/assets/ping.wav");

        // Init ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        (void)io;

        ImGui::StyleColorsDark();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window.nativeHandle(), true);
        ImGui_ImplOpenGL3_Init("#version 330");

        while (!window.shouldClose()) {
            window.pollEvents();

            glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Start ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // Your UI
            ImGui::Begin("Hello, MyEngine!");
            ImGui::Text("This is ImGui running inside your engine.");
            ImGui::End();

            // Rendering
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            window.swapBuffers();
        }

        // Cleanup
        Myeng::AudioEngine::shutdown();
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

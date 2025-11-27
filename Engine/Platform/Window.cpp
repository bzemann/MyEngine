#include "Platform/Window.hpp"

#include <stdexcept>
#include <iostream>

#include <GLFW/glfw3.h>

namespace Myeng {

static bool s_glfwInitialized = false;

Window::Window(const WindowDesc& desc)
    : m_desc(desc)
{
    if (!s_glfwInitialized) {
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }
        s_glfwInitialized = true;
    }

    // On macOS you often want this for modern OpenGL:
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    m_handle = glfwCreateWindow(
        static_cast<int>(m_desc.width),
        static_cast<int>(m_desc.height),
        m_desc.title.c_str(),
        nullptr, nullptr
    );

    if (!m_handle) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(m_handle);
    glfwSwapInterval(m_desc.vsync ? 1 : 0);
}

Window::~Window() {
    if (m_handle) {
        glfwDestroyWindow(m_handle);
        m_handle = nullptr;
    }
    // you could glfwTerminate() when last window closes if you track that
}

void Window::pollEvents() {
    glfwPollEvents();
}

void Window::swapBuffers() {
    glfwSwapBuffers(m_handle);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(m_handle);
}

} // namespace myeng

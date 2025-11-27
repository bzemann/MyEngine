#pragma once

#include <string>
#include "Core/Config.hpp"

struct GLFWwindow;  // forward declaration

namespace Myeng {

struct WindowDesc {
    std::string title  = "MyEngine";
    u32         width  = 1280;
    u32         height = 720;
    bool        vsync  = true;
};

class Window {
public:
    Window(const WindowDesc& desc);
    ~Window();

    void pollEvents();
    void swapBuffers();

    bool shouldClose() const;

    u32  width()  const { return m_desc.width; }
    u32  height() const { return m_desc.height; }

    GLFWwindow* nativeHandle() const { return m_handle; }

private:
    void initGLFW();

private:
    WindowDesc  m_desc;
    GLFWwindow* m_handle = nullptr;
};

} // namespace myeng

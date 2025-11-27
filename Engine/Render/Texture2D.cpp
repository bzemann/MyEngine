#include "Render/Texture2D.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdexcept>
#include <GLFW/glfw3.h> // for OpenGL headers on macOS

namespace Myeng {

Texture2D::Texture2D(const std::string& path) {
    int w, h, channels;
    stbi_set_flip_vertically_on_load(1);
    unsigned char* data = stbi_load(path.c_str(), &w, &h, &channels, 4);
    if (!data) {
        throw std::runtime_error("Failed to load texture: " + path);
    }

    m_width  = static_cast<u32>(w);
    m_height = static_cast<u32>(h);

    glGenTextures(1, &m_rendererId);
    glBindTexture(GL_TEXTURE_2D, m_rendererId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, data);

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}

Texture2D::~Texture2D() {
    if (m_rendererId != 0) {
        glDeleteTextures(1, &m_rendererId);
    }
}

void Texture2D::bind(u32 slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_rendererId);
}

} // namespace myeng

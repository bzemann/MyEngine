#pragma once

#include <string>
#include "Core/Config.hpp"

namespace Myeng {

class Texture2D {
public:
    Texture2D(const std::string& path);
    ~Texture2D();

    void bind(u32 slot = 0) const;

    u32 width()  const { return m_width; }
    u32 height() const { return m_height; }

private:
    u32 m_rendererId = 0;
    u32 m_width      = 0;
    u32 m_height     = 0;
};

} // namespace myeng

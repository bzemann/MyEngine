#pragma once

#include <string>

namespace Myeng {

class AudioEngine {
public:
    static void init();
    static void shutdown();

    static void playSound(const std::string& path);
};

} // namespace myeng

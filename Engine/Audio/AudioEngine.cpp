#include "Audio/AudioEngine.hpp"

#define MINIAUDIO_IMPLEMENTATION
#include "External/miniaudio.h"

#include <stdexcept>

namespace Myeng {

static ma_engine g_engine;
static bool      g_initialized = false;

void AudioEngine::init() {
    if (g_initialized) return;

    ma_result result = ma_engine_init(nullptr, &g_engine);
    if (result != MA_SUCCESS) {
        throw std::runtime_error("Failed to initialize miniaudio engine");
    }
    g_initialized = true;
}

void AudioEngine::shutdown() {
    if (!g_initialized) return;
    ma_engine_uninit(&g_engine);
    g_initialized = false;
}

void AudioEngine::playSound(const std::string& path) {
    if (!g_initialized) return;
    ma_engine_play_sound(&g_engine, path.c_str(), nullptr);
}

} // namespace myeng

#include "fft/fft.hpp"
#include "music.hpp"

std::vector<float> vs::music::getSamples() const {
    std::vector<float> data(vs::fft::scount, 0.0f);
    double srate = buffer.getSampleRate() * buffer.getChannelCount();
    uint64_t samples = buffer.getSampleCount();
    unsigned channels = buffer.getChannelCount();

    uint64_t current = sound.getPlayingOffset().asMicroseconds() * (srate / 1000000);
    if (current < (samples - vs::fft::scount)) {
        for (unsigned i = 0; i < vs::fft::scount; ++i) {
            data[i] = (float) *(buffer.getSamples() + current + i*channels);
        }
    }

    return data;
}

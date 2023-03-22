#include "vis/glow.hpp"

const std::vector<uint8_t> vs::vis::glow::leds() const {
    std::vector<uint8_t> buffer(vs::gfx::ledcount, 0);

    for (unsigned i = 0; i < vs::gfx::ledcount; ++i) {
        buffer[(i*3)]     = 0;
        buffer[(i*3) + 1] = 0;
        buffer[(i*3) + 2] = 0;
    }

    return buffer;
}

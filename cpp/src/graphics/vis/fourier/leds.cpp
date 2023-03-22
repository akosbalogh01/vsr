#include "vis/fourier.hpp"

const std::vector<uint8_t> vs::vis::fourier::leds() const {
    std::vector<uint8_t> buffer(vs::gfx::ledcount*3, 0);

    for (unsigned i = 0; i < vs::gfx::ledcount; ++i) {
        const sf::Color c = bman[i].getColor();
        unsigned bha = bman[i].getHeight();
        float    bhr = (float) bha/vs::gfx::layout::bheight; //0-1
        buffer[(i*3)]     = c.g * bhr;
        buffer[(i*3) + 1] = c.r * bhr;
        buffer[(i*3) + 2] = c.b * bhr;
    }

    return buffer;
}

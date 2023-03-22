#include "vis/fourier.hpp"

unsigned vs::vis::fourier::binHeight(const unsigned bin) const {

    double h = bins[bin] * vs::gfx::layout::bheight;
    if (h < 0.0) {
        h = 0.0;
    } else if (h > vs::gfx::layout::bheight) {
        h = vs::gfx::layout::bheight;
    }
    return h;
}

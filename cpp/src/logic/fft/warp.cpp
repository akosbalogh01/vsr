#include "fft/fft.hpp"

static const unsigned wridx[] = {
    #include "fft/wridx.dat"
};

const std::vector<float> vs::fft::func::warp(const std::vector<vs::t::cx>& in) {
    const double maxval = 8192;
    std::vector<float> out(vs::gfx::ledcount, 0);
    for (unsigned i = 0; i < vs::gfx::ledcount; i++) {
        out[i] = 0.0;
        for (unsigned j = wridx[i]; j < wridx[i+1]; j++) {
            out[i] += log10(sqrt(pow(in[j].imag(), 2) + pow(in[j].real(), 2)+2.5)/maxval)/3.62;
        }
        out[i] /= wridx[i+1]-wridx[i];
    }
    return out;
}

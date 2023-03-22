#include "fft/fft.hpp"

static const float wdata[vs::fft::scount] = {
    #include "fft/wdata.dat"
};

void vs::fft::func::window(std::vector<float>& xs) {
    for (unsigned i = 0; i < xs.size(); i++) {
        xs[i] *= wdata[i];
    }
}

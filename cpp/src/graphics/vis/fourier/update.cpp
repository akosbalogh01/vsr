#include "fft/fft.hpp"
#include "vis/fourier.hpp"

void vs::vis::fourier::update() {
    std::vector<float>     time_samples = playing->getSamples();
    std::vector<vs::t::cx> freq_samples(vs::fft::scount, std::complex<float>(0));

    vs::fft::func::window(time_samples);
    freq_samples = vs::fft::func::fft(time_samples);
    bins = vs::fft::func::warp(freq_samples);

    // current brightness level
    unsigned br = playing->getModBrightness();

    for (unsigned i = 0; i < vs::gfx::ledcount; ++i) {
        sf::Color cr = playing->getBinColor(i);
        float r = (float) br/100 * cr.r;
        float g = (float) br/100 * cr.g;
        float b = (float) br/100 * cr.b;
        bman[i].setColor(sf::Color(r, g, b));
        bman[i].setHeight(binHeight(i));
    }
}

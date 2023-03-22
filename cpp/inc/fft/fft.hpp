#ifndef VISU_FFT
#define VISU_FFT

#include <vector>
#include <complex>
#include "consts.hpp"

namespace vs {
    namespace fft {
        const int scount = 8192;
        constexpr int log2sc = log2(scount);

        class func {

        public:
            static const std::vector<vs::t::cx> fft(const std::vector<float>&);
            static const std::vector<float> warp(const std::vector<vs::t::cx>&);
            static void window(std::vector<float>&);
        };
    }
}


#endif

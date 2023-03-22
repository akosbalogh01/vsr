#include "fft/fft.hpp"

/*
    FFT algorithm copied from:
    https://www.geeksforgeeks.org/iterative-fast-fourier-transformation-polynomial-multiplication/
*/

static inline unsigned bitReverse(unsigned x, const unsigned log2n) {
    unsigned n = 0;
    for (unsigned i = 0; i < log2n; i++)
    {
        n <<= 1;
        n |= (x & 1);
        x >>= 1;
    }
    return n;
}

const std::vector<vs::t::cx> vs::fft::func::fft(const std::vector<float>& a) {
    std::vector<vs::t::cx> bins(vs::fft::scount, std::complex<float>(0));
    const float PI = 3.1415926535;

    // bit reversal of the given array
    for (unsigned int i = 0; i < vs::fft::scount; ++i) {
        int rev = bitReverse(i, vs::fft::log2sc);
        bins[i] = a[rev];
    }

    // j is iota
    const vs::t::cx J(0, 1);
    for (int s = 1; s <= vs::fft::log2sc; ++s) {
        int m = 1 << s; // 2 power s
        int m2 = m >> 1; // m2 = m/2 -1
        vs::t::cx w(1, 0);

        // principle root of nth complex
        // root of unity.
        vs::t::cx wm = exp(J * (PI / m2));
        for (int j = 0; j < m2; ++j) {
            for (int k = j; k < vs::fft::scount; k += m) {

                // t = twiddle factor
                vs::t::cx t = w * bins[k + m2];
                vs::t::cx u = bins[k];

                // similar calculating y[k]
                bins[k] = u + t;

                // similar calculating y[k+n/2]
                bins[k + m2] = u - t;
            }
            w *= wm;
        }
    }

    return bins;
}

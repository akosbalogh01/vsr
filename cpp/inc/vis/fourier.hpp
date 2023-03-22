#ifndef VISU_VIS_FOURIER
#define VISU_VIS_FOURIER

#include <vector>
#include <complex>
#include "parents.hpp"
#include "man/bars.hpp"

namespace vs {
    namespace vis {
        class fourier: public visualisable {
        private:
            unsigned maxbr, curbr; // maximum and current brightness level
            vs::man::bars bman;
            std::vector <float> bins;

            unsigned binHeight(const unsigned) const;

        public:
            fourier() = delete;
            fourier(const fourier&) = delete;
            explicit fourier(vs::t::rtarget, vs::t::mptr);

            void update() override;
            void render() override;
            const std::vector<uint8_t> leds() const override;
        };
    }
}

#endif // VISU_VIS_FOURIER

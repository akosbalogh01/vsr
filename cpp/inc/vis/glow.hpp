#ifndef VISU_VIS_GLOW
#define VISU_VIS_GLOW

#include "parents.hpp"
#include "man/bars.hpp"

namespace vs {
    namespace vis {
        class glow: public visualisable {
        private:
            vs::man::bars bman;

        public:
            glow() = delete;
            glow(const glow&) = delete;
            glow(const glow&&) = delete;
            explicit glow(vs::t::rtarget, vs::t::mptr);

            void update() override;
            void render() override;
            const std::vector<uint8_t> leds() const override;
        };
    }
}

#endif // VISU_VIS_GLOW

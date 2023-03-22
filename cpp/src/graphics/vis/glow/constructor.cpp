#include "consts.hpp"
#include "man/settings.hpp"
#include "vis/glow.hpp"

vs::vis::glow::glow(vs::t::rtarget w, vs::t::mptr m): visualisable(w, m), bman(w) {
    for (unsigned i = 0; i < vs::gfx::ledcount; ++i) {
        bman[i].setHeight(vs::gfx::layout::bheight, false);
        bman[i].setColor(sf::Color(1, 0, 0));
    }
}

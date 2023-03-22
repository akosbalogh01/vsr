#include "metadata.hpp"
#include "graphics.hpp"

vs::graphics::graphics(vs::t::rtarget window, vs::t::mptr m, vs::man::serial* const s): renderable(window), player(m), sman(s) {
    font.loadFromFile(vs::path::font);
    text.setFont(font);
    text.setFillColor(vs::gfx::color::text);
    wsize = target->getSize();
}

vs::graphics::~graphics() {

}

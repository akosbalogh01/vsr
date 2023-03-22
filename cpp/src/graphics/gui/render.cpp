#include "graphics.hpp"

void vs::graphics::render() {
    drawRect(
        sf::Vector2f(vs::gfx::layout::x1, vs::gfx::layout::y1),
        sf::Vector2f(wsize.x - (2 * vs::gfx::layout::x1), wsize.y - (2 * vs::gfx::layout::y1)),
        vs::gfx::color::accent
    );

    drawTimedata();
    drawMetadata();
    drawCom();
}

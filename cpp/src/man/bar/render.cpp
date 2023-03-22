#include "man/bars.hpp"

void vs::man::bars::render() {
    // align bars to actual window size
    sf::Vector2u wsize = target->getSize();
    unsigned xoff = vs::gfx::layout::xt * wsize.x;
    unsigned yoff = vs::gfx::layout::yt * wsize.y;
    float width = (float) (wsize.x - 2*xoff)/vs::gfx::ledcount;
    for (unsigned i = 0; i < vs::gfx::ledcount; ++i) {
        barv[i].setWidth(width);
        barv[i].setPosition(sf::Vector2f(xoff + i*width, yoff - 2*vs::gfx::layout::y1));

        //barv[i].setVertices(, sf::Vector2f(width, vs::gfx::layout::bheight));
        barv[i].render();
    }
}

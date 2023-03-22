#include "bar.hpp"

vs::bar::bar(const vs::bar& other): renderable(other.target) {
    curheight = 0;
    quad = sf::VertexArray(sf::Quads, 4);
    for (unsigned i = 0; i < 4; ++i) {
        quad[i].position = other.quad[i].position;
        quad[i].color = other.quad[i].color;
    }
}

vs::bar::bar(const vs::bar&& other): renderable(other.target) {
    quad = sf::VertexArray(sf::Quads, 4);
    for (unsigned i = 0; i < 4; ++i) {
        quad[i].position = other.quad[i].position;
        quad[i].color = other.quad[i].color;
    }
}

vs::bar::bar(vs::t::rtarget const window): renderable(window) {
    quad = sf::VertexArray(sf::Quads, 4);
}

#include "man/window.hpp"

void vs::man::window::render() {
    target.clear(vs::gfx::color::bg);
    gui.render();
    vman.render();
    target.display();
}

#include "man/debug.hpp"

vs::man::debug::debug(const vs::t::mptr m): player(m) {
    for (unsigned i = 0; i < vs::man::debug::_SIZE; ++i) {
        timers[i] = sf::Time::Zero;
        prev[i] = 0;
    }

    font.loadFromFile(vs::path::font);
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Red);

    runtime.restart();
}

vs::man::debug::~debug() {
    closeOverlay();
}

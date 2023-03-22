#include <iostream>
#include "consts.hpp"
#include "man/debug.hpp"

void vs::man::debug::toggleOverlay(const sf::Event& event) {
    if (event.key.code == sf::Keyboard::D) {
        if (overlay.isOpen()) {
            std::cout << "Disabled debug overlay." << std::endl;
            overlay.close();
        }
        else {
            std::cout << "Enabled debug overlay." << std::endl;
            overlay.create(sf::VideoMode(500, 200), "Debug overlay", sf::Style::Titlebar);
            overlay.setFramerateLimit(vs::gfx::framelimit);
            //overlay.setActive(false);
        }
    }
}

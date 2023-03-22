#include <iostream>
#include "man/window.hpp"

bool vs::man::window::pollEvent(sf::Event& event) {
    return target.pollEvent(event);
}

void vs::man::window::selectVisualisation(const sf::Event& event) {
    vman.selectVisualisation(event);
}

void vs::man::window::toggleVisualisation(const sf::Event& event) {
    vman.toggleEnabled(event);
}

void vs::man::window::displayMetadata() {
    gui.toggleMetadata();
}


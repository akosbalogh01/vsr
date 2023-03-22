#include <iostream>
#include "man/serial.hpp"

void vs::man::serial::toggleEnabled(const sf::Event& event) {
    if (event.key.code == sf::Keyboard::V) {
        if (en) {
            std::cout << "Disabled VS transmission" << std::endl;
            disable();
        }
        else {
            std::cout << "Enabled VS transmission" << std::endl;
            init();
        }
    }
}

#include "man/visualiser.hpp"

void vs::man::visualiser::selectVisualisation(const sf::Event& event) {
    if ((event.key.code >= sf::Keyboard::Num0) && (event.key.code <= sf::Keyboard::Num9)) {
        const unsigned v = event.key.code - sf::Keyboard::Num0;
        const vtype t = static_cast<vtype>(v);

        std::map<vtype, std::unique_ptr<vs::visualisable>>::iterator i;
        i = vmap.find(t);
        if (i != vmap.end()) {
            std::cout << "Selected VS[" << std::to_string(t) << "]" << std::endl;
            current = t;
        }
        else {
            std::cout << "Invalid VSID" << std::endl;
        }
    }
}

void vs::man::visualiser::toggleEnabled(const sf::Event& event) {
    if (event.key.code == sf::Keyboard::V) {
        if (en) {
            std::cout << "Disabled visualisation" << std::endl;
            en = false;
        }
        else {
            std::cout << "Enabled visualisation" << std::endl;
            en = true;
        }
    }
}

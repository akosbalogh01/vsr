#include "man/settings.hpp"
#include "man/window.hpp"

vs::man::window::window(vs::t::mptr m, const std::string& title, vs::man::serial* const sman): player(m), gui(&target, m, sman), vman(&target, m) {
    using namespace vs::man;

    std::string header = title.substr(0, title.length() - 4);
    unsigned x = std::stoi(settings::smap[settings::WINWIDTH]);
    unsigned y = std::stoi(settings::smap[settings::WINHEIGHT]);

    if (vs::man::settings::smap[vs::man::settings::WFULLSCREEN] == "true") {
        target.create(sf::VideoMode(x, y), header, sf::Style::Fullscreen);
    }
    else {
        target.create(sf::VideoMode(x, y), header);
    }

    target.setFramerateLimit(vs::gfx::framelimit);
    gui.resizeInterface(sf::Vector2u(x, y));
}

#include "logic.hpp"

vs::logic::logic(const int argc, const char** argv, vs::t::mptr m): player(m), sman(argv[1]), wman(m, argv[2], &tman), aman(m, argv[2]), dman(m) {
    using namespace vs;
    using namespace vs::man;
    using namespace std::placeholders;

    eman.add(sf::Event::Resized, fpair(std::bind(&man::window::windowResize, &wman, _1), std::bind(&man::window::windowResize, &wman, _1)));
    eman.add(sf::Event::Closed, fpair(std::bind(&man::window::windowClose, &wman, _1), std::bind(&man::window::windowClose, &wman, _1)));
    eman.add(sf::Event::KeyReleased, fpair(std::bind(&man::window::windowClose, &wman, _1), std::bind(&man::window::windowClose, &wman, _1)));
    eman.add(sf::Event::KeyReleased, fpair(std::bind(&logic::eventPaused, this, _1), std::bind(&man::audio::toggleAutoplay, &aman, _1)));
    eman.add(sf::Event::KeyReleased, fpair(std::bind(&man::audio::eventPrevSong, &aman, _1), std::bind(&man::audio::jumpBack, &aman, _1)));
    eman.add(sf::Event::KeyReleased, fpair(std::bind(&man::audio::eventNextSong, &aman, _1), std::bind(&man::audio::jumpForward, &aman, _1)));
    eman.add(sf::Event::KeyReleased, fpair(std::bind(&man::window::toggleVisualisation, &wman, _1), std::bind(&man::serial::toggleEnabled, &tman, _1)));
    eman.add(sf::Event::KeyReleased, fpair(std::bind(&man::debug::toggleOverlay, &dman, _1), std::bind(&man::debug::toggleOverlay, &dman, _1)));
    eman.add(sf::Event::KeyReleased, fpair(std::bind(&man::window::selectVisualisation, &wman, _1), std::bind(&man::window::selectVisualisation, &wman, _1)));
    eman.add(sf::Event::MouseWheelScrolled, fpair(std::bind(&man::audio::setMaxVolume, &aman, _1), std::bind(&man::audio::setMaxBrightness, &aman, _1)));
    eman.add(sf::Event::MouseButtonReleased, fpair(std::bind(&logic::eventTimestamp, this, _1), std::bind(&logic::eventTimestamp, this, _1)));

    started = false;
    paused = true;
}

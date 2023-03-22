#include <iostream>
#include "logic.hpp"

void vs::logic::update() {
    dman.signal(vs::man::debug::UPDATE);

    if (started) {
        if (!paused) {
            if (playing->isOver()) {
                std::cout << "Song over" << std::endl;
                if (aman.getAutoplay()) {
                    aman.nextSong();
                }
                else {
                    togglePaused();
                }
            }
            else {
                playing->update();
                wman.update();

                dman.signal(vs::man::debug::TRANSMIT);
                tman.transmit(wman.leds());
                dman.signal(vs::man::debug::TRANSMIT);
            }
        }
    }

    dman.signal(vs::man::debug::UPDATE);
}

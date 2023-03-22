#include <fstream>
#include <iostream>
#include "man/audio.hpp"

void vs::man::audio::setMaxVolume(const sf::Event& event) {
    unsigned volume = playing->getMaxVolume();
    const int delta = vcoef * (int) event.mouseWheelScroll.delta;
    const int temp = volume + delta;
    if ((temp >= 0) && (temp <= 100)) {
        volume = temp;
    }

    playing->setMaxVolume(volume);
    std::cout << "Set max volume: " << volume << std::endl;
}

void vs::man::audio::setMaxBrightness(const sf::Event& event) {
    unsigned brightness = playing->getMaxBrightness();
    const int delta = vs::gfx::brightness::coeff * (int) event.mouseWheelScroll.delta;
    const int temp = brightness + delta;
    if ((temp >= 0) && (temp <= 100)) {
        brightness = temp;
    }

    playing->setMaxBrightness(brightness);
    std::cout << "Set max brightness: " << brightness << std::endl;
}

void vs::man::audio::togglePaused() {
    if (paused) {
        playing->play();
        paused = false;
    }
    else {
        playing->pause();
        paused = true;
    }
}

void vs::man::audio::prevSong() {
    pman.prev(paused);
}

void vs::man::audio::nextSong() {
    pman.next(paused);
}

bool vs::man::audio::getAutoplay() const {
    return autoplay;
}

void vs::man::audio::stopPlayback() {
    playing->dropBuffer();
}

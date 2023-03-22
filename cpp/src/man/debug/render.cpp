#include "man/debug.hpp"

static inline std::string toString(const sf::Time& time) {
    char buf[10];
    unsigned m = time.asSeconds()/60;
    unsigned s = ((int) time.asSeconds()) % 60;

    sprintf(buf, "%d:%02d", m, s);
    return std::string(buf);
}

void vs::man::debug::drawText(const unsigned x, const unsigned y, const std::string& str) {
    text.setString(str);
    text.setPosition(sf::Vector2f(x, y));
    overlay.draw(text);
}

void vs::man::debug::renderOverlay() {
    if (overlay.isOpen()) {
        overlay.clear(sf::Color::Black);
        drawText(10, 10, "runtime: " + toString(runtime.getElapsedTime()));
        drawText(10, 30, "frame: " + std::to_string(prev[vs::man::debug::FRAME]/1000) + "ms");
        drawText(10, 50, "event: " + std::to_string(prev[vs::man::debug::EVENT]) + "us");
        drawText(10, 70, "update: " + std::to_string(prev[vs::man::debug::UPDATE]) + "us");
        drawText(10, 90, "transmit: " + std::to_string(prev[vs::man::debug::TRANSMIT]) + "us");
        drawText(10, 110, "render: " + std::to_string(prev[vs::man::debug::RENDER]) + "us");
        drawText(200, 10, "playing");
        drawText(200, 30, playing->getTitle());
        drawText(200, 50, std::to_string(playing->getTime().first.asMilliseconds()) + "ms");
        drawText(200, 70, std::to_string(playing->getTime().second.asMilliseconds()) + "ms");
        drawText(200, 90, "max vol: " + std::to_string(playing->getMaxVolume()) + "%");
        drawText(200, 110, "cur vol: " + std::to_string(playing->getModVolume()) + "%");
        drawText(200, 130, "max brt: " + std::to_string(playing->getMaxBrightness()) + "%");
        drawText(200, 150, "cur brt: " + std::to_string(playing->getModBrightness()) + "%");
        //drawText(370, "channels: " + std::to_string(playing->getChannelCount()));
        //drawText(390, "sample count: " + std::to_string(playing->getSampleCount()));
        //drawText(410, "sample rate: " + std::to_string(playing->getSampleRate()));
        overlay.display();
    }
}

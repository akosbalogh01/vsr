#include "point.hpp"

sf::Time vs::point::getStamp() const {
    return sf::milliseconds(stamp);
}

unsigned vs::point::getVolume() const {
    return volume;
}

unsigned vs::point::getBrightness() const {
    return brightness;
}

sf::Color vs::point::getBinColor(const unsigned bin) const {
    return bins[bin];
}

void vs::point::setStamp(const sf::Time& t) {
    stamp = t.asMilliseconds();
}
